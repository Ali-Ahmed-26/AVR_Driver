/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    EXI_Driver  *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "D:\AVR_WS\COTS\MCAL\DIO_Driver\DIO_interface.h"
#include "EXI_register.h"
#include "EXI_interface.h"
#include "EXI_configration.h"
#include "EXI_private.h"

/*Global pointer to function to hold INT0 ISR address*/
void (*EXI_VidPtrINT0Func)(void) = NULL;
/*Global pointer to function to hold INT1 ISR address*/
void (*EXI_VidPtrINT1Func)(void) = NULL;
/*Global pointer to function to hold INT2 ISR address*/
void (*EXI_VidPtrINT2Func)(void) = NULL;

/*Pre-build configuration*/
//Initialization function of External Interrupt 0
void EXI0_VidINT0Init(void)
{
   /* Check Sense Control*/
	#if INT0_SENSE == Low_Level
	    CLR_BIT(MCUCR , ISC00);
	    CLR_BIT(MCUCR , ISC01);

	#elif INT0_SENSE == Any_Logical_Change
	      SET_BIT(MCUCR , ISC00);
	      CLR_BIT(MCUCR , ISC01);

    #elif INT0_SENSE == Falling_Edge
	      CLR_BIT(MCUCR , ISC00);
	      SET_BIT(MCUCR , ISC01);

    #elif INT0_SENSE == Rising_Edge
	      SET_BIT(MCUCR , ISC00);
	      SET_BIT(MCUCR , ISC01);

    #else
    #error "Wrong INT0_SENSE Configuration option"
    #endif

    /* Check Peripheral interrupt enable initial state*/
    #if INT0_INITIAL_STATE == ENABLED
	    SET_BIT(GICR , GICR_INT0);
    #elif INT0_INITIAL_STATE == DISABLED
	    CLR_BIT(GICR , GICR_INT0);
    #else
    #error "Wrong INT0_INITIAL_STATE Configuration option"
    #endif

	//Configure interrupt 0 Port PD2 as Input
	DIO_VidSetPinDirection(PORT_D , PIN_2 , INPUT);
	//Configure PullUP Resistor
	DIO_VidSetPinValue(PORT_D , PIN_2 , HIGH);
}

//Initialization function of External Interrupt 1
void EXI1_VidINT1Init(void)
{
   /*1- Check Sense Control*/
	#if INT1_SENSE == Low_Level
	    CLR_BIT(MCUCR , ISC10);
	    CLR_BIT(MCUCR , ISC11);

	#elif INT1_SENSE == Any_Logical_Change
	      SET_BIT(MCUCR , ISC10);
	      CLR_BIT(MCUCR , ISC11);

    #elif INT1_SENSE == Falling_Edge
	      CLR_BIT(MCUCR , ISC10);
	      SET_BIT(MCUCR , ISC11);

    #elif INT1_SENSE == Rising_Edge
	      SET_BIT(MCUCR , ISC10);
	      SET_BIT(MCUCR , ISC11);

    #else
    #error "Wrong INT1_SENSE Configuration option"
    #endif

    /* Check Peripheral interrupt enable initial state*/
    #if INT1_INITIAL_STATE == ENABLED
	    SET_BIT(GICR , GICR_INT1);
    #elif INT1_INITIAL_STATE == DISABLED
	      CLR_BIT(GICR , GICR_INT1);
    #else
    #error "Wrong INT1_INITIAL_STATE Configuration option"
    #endif

	//Configure interrupt 1 Port PD3 as Input
	DIO_VidSetPinDirection(PORT_D , PIN_3 , INPUT);
    //Configure PullUP Resistor
	DIO_VidSetPinValue(PORT_D , PIN_3 , HIGH);
}

//Initialization function of External Interrupt 2
void EXI2_VidINT2Init(void)
{
   /*1- Check Sense Control*/
    #if INT2_SENSE == Falling_Edge
	      CLR_BIT(MCUCR , ISC2);

    #elif INT2_SENSE == Rising_Edge
	      SET_BIT(MCUCR , ISC2);

    #else
    #error "Wrong INT2_SENSE Configuration option"
    #endif

    /* Check Peripheral interrupt enable initial state*/
    #if INT2_INITIAL_STATE == ENABLED
	    SET_BIT(GICR , GICR_INT2);
    #elif INT2_INITIAL_STATE == DISABLED
	      CLR_BIT(GICR , GICR_INT2);
    #else
    #error "Wrong INT2_INITIAL_STATE Configuration option"
    #endif

	//Configure interrupt 2 Port PB2 as Input
	DIO_VidSetPinDirection(PORT_B , PIN_2 , INPUT);
    //Configure PullUP Resistor
	DIO_VidSetPinValue(PORT_B , PIN_2 , HIGH);
 }

/* Description: A function to set the required sense control of INT0 using postbuild configuration
 * Input: Copy_u8INT0SenseControl , Options are: 1- Low_Level
                                                 2- Any_Logical_Change
                                                 3- Falling_Edge
                                                 4- Rising_Edge  */
void EXI0_VidInit(u8 Copy_u8INT0SenseControl)
{
	//Enable sensing Bits
	switch(Copy_u8INT0SenseControl)
	{
     case (Low_Level) : CLR_BIT(MCUCR , ISC00); CLR_BIT(MCUCR , ISC01);break;
     case (Any_Logical_Change) : CLR_BIT(MCUCR , ISC01); SET_BIT(MCUCR , ISC00);break;
	 case (Falling_Edge) : CLR_BIT(MCUCR , ISC00); SET_BIT(MCUCR , ISC01);break;
	 case (Rising_Edge) : SET_BIT(MCUCR , ISC00); SET_BIT(MCUCR , ISC01);break;
	}

   //Configure interrupt 0 Port PD2 as Input
   DIO_VidSetPinDirection(PORT_D , PIN_2 , INPUT);
   //Configure PullUP Resistor
   DIO_VidSetPinValue(PORT_D , PIN_2 , HIGH);
}


/* Description: A function to set the required sense control of INT1 using postbuild configuration
 * Input: Copy_u8INT1SenseControl , Options are: 1- Low_Level
                                                 2- Any_Logical_Change
                                                 3- Falling_Edge
                                                 4- Rising_Edge  */
void EXI1_VidInit(u8 Copy_u8INT1SenseControl)
{
	//Enable sensing Bits
	switch(Copy_u8INT1SenseControl)
	{
	 case (Low_Level) : CLR_BIT(MCUCR , ISC11); CLR_BIT(MCUCR , ISC10);break;
	 case (Any_Logical_Change) : CLR_BIT(MCUCR , ISC11); SET_BIT(MCUCR , ISC10);break;
	 case (Falling_Edge) : CLR_BIT(MCUCR , ISC10); SET_BIT(MCUCR , ISC11);break;
     case (Rising_Edge) : SET_BIT(MCUCR , ISC11); SET_BIT(MCUCR , ISC10);break;
	}

	//Configure interrupt 1 Port PD3 as Input
	DIO_VidSetPinDirection(PORT_D , PIN_3 , INPUT);
	//Configure PullUP Resistor
	DIO_VidSetPinValue(PORT_D , PIN_3 , HIGH);
}




/* Description: A function to set the required sense control of INT2 using postbuild configuration
 * Input: Copy_u8INT2SenseControl , Options are:
                                                 1- Falling_Edge
                                                 2- Rising_Edge  */
void EXI2_VidInit(u8 Copy_u8INT2SenseControl)
{
	//Enable sensing Bit for rising edge
	switch(Copy_u8INT2SenseControl)
	{
	 case (Falling_Edge): CLR_BIT(MCUCSR , ISC2);break;
	 case (Rising_Edge) : SET_BIT(MCUCSR , ISC2);break;
	}
	//Configure interrupt 2 Port PB2 as Input
	DIO_VidSetPinDirection(PORT_B , PIN_2 , INPUT);
	//Configure PullUP Resistor
	DIO_VidSetPinValue(PORT_B , PIN_2 , HIGH);
 }



void EXI0_VidEnable()
{
	//Enable interrupt 0
	SET_BIT(GICR , GICR_INT0);
}

void EXI1_VidEnable()
{
	//Enable interrupt 1
    SET_BIT(GICR , GICR_INT1);
}

void EXI2_VidEnable()
{
	//Enable interrupt 2
	SET_BIT(GICR , GICR_INT2);
}

void EXI0_VidDisable()
{
	//Disable interrupt 0
	CLR_BIT(GICR , GICR_INT0);
}

void EXI1_VidDisable()
{
	//Disable interrupt 1
	CLR_BIT(GICR , GICR_INT1);
}

void EXI2_VidDisable()
{
	//Disable interrupt 2
	CLR_BIT(GICR , GICR_INT2);
}
