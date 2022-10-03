/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Interrupt   *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "Interrupt_register.h"
#include "Interrupts_interface.h"
#include "Interrupt_private.h"

static void (*ISR_VidPtrCallBackFunc[20])(void) ={NULL};

static u8 INTERRUPT_ID = 0;

void INTERRUPT_VidSetINTSource(INTERUUPT_SOURCE_TYPE Copy_EnumINTSource , INTERRUPT_STATE_TYPE Copy_EnumINTState)
{


	if(Copy_EnumINTState == ENABLE)
	{
		switch(Copy_EnumINTSource)
		{
		case (EXTERNAL_INT0): SET_BIT(GICR , GICR_INT0); break;
		case (EXTERNAL_INT1): SET_BIT(GICR , GICR_INT1); break;
		case (EXTERNAL_INT2): SET_BIT(GICR , GICR_INT2); break;
		case (TIMER2_CTC):    SET_BIT(TIMSK , TIMSK_OCIE2); break;
		case (TIMER2_OVF):    SET_BIT(TIMSK , TIMSK_TOIE2); break;
		case (TIMER1_ICU):    SET_BIT(TIMSK , TIMSK_TICIE1); break;
		case (TIMER1_CTC_A):  SET_BIT(TIMSK , TIMSK_OCIE1A); break;
		case (TIMER1_CTC_B):  SET_BIT(TIMSK , TIMSK_OCIE1B); break;
		case (TIMER1_OVF):    SET_BIT(TIMSK , TIMSK_TOIE1); break;
		case (TIMER0_CTC):    SET_BIT(TIMSK , TIMSK_OCIE0); break;
		case (TIMER0_OVF):    SET_BIT(TIMSK , TIMSK_TOIE0); break;
		case (ADC_CONVERSION_COMPLETE): SET_BIT(ADCSRA , ADCSRA_ADIE); break;
		}
	}
	else if(Copy_EnumINTState == ENABLE)
	{
		switch(Copy_EnumINTSource)
		{
		case (EXTERNAL_INT0): CLR_BIT(GICR , GICR_INT0); break;
		case (EXTERNAL_INT1): CLR_BIT(GICR , GICR_INT1); break;
		case (EXTERNAL_INT2): CLR_BIT(GICR , GICR_INT2); break;
		case (TIMER2_CTC):    CLR_BIT(TIMSK , TIMSK_OCIE2); break;
		case (TIMER2_OVF):    CLR_BIT(TIMSK , TIMSK_TOIE2); break;
		case (TIMER1_ICU):    CLR_BIT(TIMSK , TIMSK_TICIE1); break;
		case (TIMER1_CTC_A):  CLR_BIT(TIMSK , TIMSK_OCIE1A); break;
		case (TIMER1_CTC_B):  CLR_BIT(TIMSK , TIMSK_OCIE1B); break;
		case (TIMER1_OVF):    CLR_BIT(TIMSK , TIMSK_TOIE1); break;
		case (TIMER0_CTC):    CLR_BIT(TIMSK , TIMSK_OCIE0); break;
		case (TIMER0_OVF):    CLR_BIT(TIMSK , TIMSK_TOIE0); break;
		case (ADC_CONVERSION_COMPLETE): CLR_BIT(ADCSRA , ADCSRA_ADIE); break;
		}
	}

}

u8 ISR_u8SetCallBack(void (*Copy_VidPtrCallBackFunc)(void) , INTERUUPT_SOURCE_TYPE Copy_INTNumber)
{
	u8 Local_u8ErrorStatus =OK;

	if(Copy_VidPtrCallBackFunc !=NULL)
	{
		INTERRUPT_ID = Copy_INTNumber;
		ISR_VidPtrCallBackFunc[INTERRUPT_ID] = Copy_VidPtrCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus =NULL_POINTER;
	}

	return Local_u8ErrorStatus;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(ISR_VidPtrCallBackFunc[INTERRUPT_ID] !=NULL)
	{
		ISR_VidPtrCallBackFunc[INTERRUPT_ID]();
	}
}



