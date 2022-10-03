/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    ADC         *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
# include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "D:\AVR_WS\COTS\MCAL\DIO_Driver\DIO_interface.h"
#include "ADC_register.h"
#include "ADC_interface.h"
#include "ADC_configration.h"
#include "ADC_private.h"

static void (*ADC_VidPtrCallBackNotificationFunc)(void) = NULL;

static u16* ADC_u16PtrReading =NULL;

u8 ADC_u8BusyState = IDLE;

void ADC_VidInit(void)
{
	/* Reference voltage selection*/
   #if VOLTAGE_REFERENCE == AREF
	   CLR_BIT(ADMUX , ADMUX_REFS0);
	   CLR_BIT(ADMUX , ADMUX_REFS1);

   #elif VOLTAGE_REFERENCE == AVCC
	     SET_BIT(ADMUX , ADMUX_REFS0);
	     CLR_BIT(ADMUX , ADMUX_REFS1);

   #elif VOLTAGE_REFERENCE == Internal_Voltage
	     SET_BIT(ADMUX , ADMUX_REFS0);
	     SET_BIT(ADMUX , ADMUX_REFS1);

   #else
   #error "Wrong VOLTAGE_REFERENCE Configuration option"
   #endif

	/*Activate left adjust result*/
   #if LEFT_ADJUST == ENABLED
	   SET_BIT(ADMUX , ADMUX_ADLAR);

   #elif LEFT_ADJUST == DISABLED
	     CLR_BIT(ADMUX , ADMUX_ADLAR);

   #else
   #error "Wrong LEFT_ADJUST Configuration option"
   #endif

	/*Set ADC Prescaler */
    ADCSRC &= PRESCALER_MASK;
    ADCSRC |= PRESCALER_DIV;

    /* Check Peripheral interrupt enable initial state*/
    #if ADC_INITIAL_STATE == ENABLED
        SET_BIT(ADCSRC , ADCSRA_ADEN);

    #elif ADC_INITIAL_STATE == DISABLED
          CLR_BIT(ADCSRC , ADCSRA_ADEN);

    #else
    #error "Wrong ADC_INITIAL_STATE Configuration option"
    #endif


    #if ADC_CONVERSION == AUTO_TRIGGER
        SET_BIT(ADCSRC , ADCSRA_ADATE);

        /*Select ADC Auto Trigger Source*/
        SFIOR &= AUTO_TRIGGER_MASK;
        SFIOR |= ADC_AUTO_TRIGGER_SOURCE;

        SET_BIT(ADCSRC , ADCSRA_ADSC);

    #elif ADC_CONVERSION == SINGLE_CONVERSTION
          CLR_BIT(ADCSRC , ADCSRA_ADATE);

    #else
    #error "Wrong ADC_AUTO_TRIGGER_MODE Configuration option"
    #endif

    #if ADC_INTERRUPT == ENABLED
        SET_BIT(ADCSRC , ADCSRA_ADIE);

   #elif ADC_INTERRUPT == DISABLED
         CLR_BIT(ADCSRC , ADCSRA_ADIE);

   #else
   #error "Wrong ADC_INTERRUPT Configuration option"
   #endif
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel , u16* Copy_u16PtrReading)
{
	u32 Local_u32Counter =0;
    u8  Local_u8ErrorState =OK;

 if(ADC_u8BusyState == IDLE)
 {
	 /*Make ADC busy in order not to work until being idle*/
	 ADC_u8BusyState = BUSY;
     #if ANALOG_CHANNEL_MODE == SINGLE_ENDED
	     ADMUX &= ADC_INPUT_CHANNEL_MASK;
	     ADMUX |= SINGLE_ENDED_INPUT;

     #elif ANALOG_CHANNEL_MODE == DIFFERENTIAL
	       ADMUX &= ADC_INPUT_CHANNEL_MASK;
           ADMUX |= DIFFERENTIAL_INPUT;

     #else
     #error "Wrong ANALOG_CHANNEL_MODE Configuration option"
     #endif

     #if ADC_CONVERSION == SINGLE_CONVERSTION
         CLR_BIT(ADCSRC , ADCSRA_ADATE);
         SET_BIT(ADCSRC , ADCSRA_ADSC);
     #endif

       /*Polling (busy waiting) until the conversion complete flag is set or counter reaching timeout value */
       while(((GET_BIT(ADCSRC , ADCSRA_ADIF)) == 0) && (Local_u32Counter != ADC_u32TIMEOUT))
       {
    	   Local_u32Counter++;
       }

       if(Local_u32Counter == ADC_u32TIMEOUT)
       {
    	   /*Loop is broken because the timeout is reached */
    	   Local_u8ErrorState = NOK;
       }
       else
       {
    	   /*Loop is broken because flag is raised*/
    	   /*Clear the conversion complete flag*/
    	   SET_BIT(ADCSRC , ADCSRA_ADIF);

    	   /*Return reading*/
          #if ADC_RESOLUTION == ADC_8_BITS
              Copy_u16PtrReading = ADCH;

          #elif ADC_RESOLUTION == ADC_10_BITS
                Copy_u16PtrReading = ADCLH;

          #else
          #error "Wrong ADC_RESOLUTION Configuration option"
          #endif

          /*Make ADC state be idle because it finished*/
          ADC_u8BusyState = IDLE;
       }
    }
   else
	 {
		 u8 Local_u8ErrorStatus = BUSY_FUNCTION;
	 }

   return Local_u8ErrorState;
 }

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel , u16* Copy_u16PtrReading , void (*Copy_VidPtrADCINTFunc)(void))
{
	u8 Local_u8ErrorStatus = OK;

	 if(ADC_u8BusyState == IDLE)
	 {
	    if((Copy_VidPtrADCINTFunc == NULL) || (Copy_u16PtrReading ==NULL))
		{
			Local_u8ErrorStatus =NULL_POINTER;
		}
		else
		{
		  /*Make ADC busy in order not to work until being idle*/
		  ADC_u8BusyState = BUSY;

		  /*Initialize the reading variable globally */
          ADC_u16PtrReading = Copy_u16PtrReading;

          /*Initialize the callback notification function globally */
          ADC_VidPtrCallBackNotificationFunc = Copy_VidPtrADCINTFunc;

		 #if ANALOG_CHANNEL_MODE == SINGLE_ENDED
			  /*Clear the MUX bits in ADMUX register*/
	          ADMUX &= ADC_INPUT_CHANNEL_MASK;
	          /*Set the required channel into the MUX bits*/
	          ADMUX |= SINGLE_ENDED_INPUT;

         #elif ANALOG_CHANNEL_MODE == DIFFERENTIAL
	           /*Clear the MUX bits in ADMUX register*/
	           ADMUX &= ADC_INPUT_CHANNEL_MASK;
	           /*Set the required channel into the MUX bits*/
               ADMUX |= DIFFERENTIAL_INPUT;

        #else
        #error "Wrong ANALOG_CHANNEL_MODE Configuration option"
        #endif

        #if ADC_CONVERSION == SINGLE_CONVERSTION
            CLR_BIT(ADCSRC , ADCSRA_ADATE);
            /*Start conversion*/
            SET_BIT(ADCSRC , ADCSRA_ADSC);
       #endif

            /*ADC interrupt enable*/
            SET_BIT(ADCSRC , ADCSRA_ADIE);
		}
	 }

	 else
	 {
		 u8 Local_u8ErrorStatus = BUSY_FUNCTION;
	 }
		return Local_u8ErrorStatus;
}


s32 map(u32 Copy_s32InputMin , u32 Copy_s32InputMax , u32 Copy_s32OutputMin , u32 Copy_s32OutputMax , u32 Copy_s32InputVal)
{
	s32 Local_s32OutputVal;

    Local_s32OutputVal =  (Copy_s32InputVal - Copy_s32InputMin);
    Local_s32OutputVal *= (Copy_s32OutputMax - Copy_s32OutputMin);
    Local_s32OutputVal /= (Copy_s32InputMax - Copy_s32InputMin);
    Local_s32OutputVal += Copy_s32OutputMin;

    return Local_s32OutputVal;
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
 {
	/*Read ADC result*/
    #if ADC_RESOLUTION == ADC_8_BITS
        *ADC_u16PtrReading = ADCH;

    #elif ADC_RESOLUTION == ADC_10_BITS
          *ADC_u16PtrReading = ADCLH;

    #else
    #error "Wrong ADC_RESOLUTION Configuration option"
    #endif

     /*Make ADC state be idle because it finished*/
     ADC_u8BusyState = IDLE;

    /*Invoke the callback notification function*/
    ADC_VidPtrCallBackNotificationFunc();

    /*Disable ADC conversion complete interrupt*/
    CLR_BIT(ADCSRC , ADCSRA_ADIE);
 }
