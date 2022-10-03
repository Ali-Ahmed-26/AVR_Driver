/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Timer0      *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/


#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "D:\AVR_WS\COTS\MCAL\DIO_Driver\DIO_interface.h"
#include "Timer0_configuration.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
#include "Timer0_register.h"

/*PreBuild Configuration for Timer0 */
void TIMER0_VidInit(void)
{
	/*Choose Timer0 mode*/
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER0_MODE == PWM_PHASE_CORRECT_MODE
	  SET_BIT(TCCR0 , TCCR0_WGM00);
	  CLR_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER0_MODE == CTC_MODE
	  CLR_BIT(TCCR0 , TCCR0_WGM00);
	  SET_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER0_MODE == PWM_FAST_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

#else
#error "Wrong TIMER0_MODE Configuration option"
#endif

#if TIMER0_COMPARE_OUTPUT_MODE == NORMAL_OC0_DISCONNECTED
	TCCR0 &= CTC_OUTPUT_MASK;

#elif TIMER0_COMPARE_OUTPUT_MODE == NON_PWM_TOGGLE_OC0_ON_CTC
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11011111;

#elif TIMER0_COMPARE_OUTPUT_MODE == NON_PWM_CLEAR_OC0_ON_CTC
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11101111;

#elif TIMER0_COMPARE_OUTPUT_MODE == NON_PWM_SET_OC0_ON_CTC
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11111111;

#elif TIMER0_COMPARE_OUTPUT_MODE == FAST_PWM_CLEAR_OC0_ON_CTC_SET_ON_TOP
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11101111;

#elif TIMER0_COMPARE_OUTPUT_MODE == FAST_PWM_SET_OC0_ON_CTC_CLEAR_ON_TOP
	  TCCR0 &= CTC_OUTPUT_MASK;
      TCCR0 |= 0b11111111;

#elif TIMER0_COMPARE_OUTPUT_MODE == PHASE_CORRECT_PWM_CLEAR_OC0_ON_UPCOUNTING_SET_ON_DOWNCOUNTING
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11101111;

#elif TIMER0_COMPARE_OUTPUT_MODE == PHASE_CORRECT_PWM_SET_OC0_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
	  TCCR0 &= CTC_OUTPUT_MASK;
	  TCCR0 |= 0b11111111;

#else
#error "Wrong TIMER0_COMPARE_OUTPUT_MODE Configuration option"
#endif

	/*Set Prescaler*/
	TCCR0 &= TCCR0_MASK;
	TCCR0 |= TIMER_PRESCALER;
}

/*Post Build Configuration for Timer0 */

void TIMER0_VidTimerInit(TIMER_MODES_TYPE Copy_EnumMode , TIMER_PRESCALER_TYPE Copy_EnumPrescaler , TIMER0_CTC_MODE_TYPE Copy_CTC_Modes)
{
	switch(Copy_EnumMode)
	{
	case (NORMAL) : CLR_BIT(TCCR0 , TCCR0_WGM00); CLR_BIT(TCCR0 , TCCR0_WGM01); break;
	case (PWM_PHASE_CORRECT) : SET_BIT(TCCR0 , TCCR0_WGM00); CLR_BIT(TCCR0 , TCCR0_WGM01); break;
	case (CTC) : CLR_BIT(TCCR0 , TCCR0_WGM00); SET_BIT(TCCR0 , TCCR0_WGM01); break;
	case (PWM_FAST) : SET_BIT(TCCR0 , TCCR0_WGM00); SET_BIT(TCCR0 , TCCR0_WGM01); break;
	}

	switch(Copy_CTC_Modes)
	{
	case (OC0_DISCONNECTED) : TCCR0 &= CTC_OUTPUT_MASK; break;
	case (CTC_NON_PWM_TOGGLE_OC0_ON_CTC) : TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11011111; break;
	case (CTC_NON_PWM_CLEAR_OC0_ON_CTC): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11101111; break;
	case (CTC_NON_PWM_SET_OC0_ON_CTC): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11111111; break;
	case (CTC_FAST_PWM_CLEAR_OC0_ON_CTC_SET_ON_TOP): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11101111; break;
	case (CTC_FAST_PWM_SET_OC0_ON_CTC_CLEAR_ON_TOP): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11111111; break;
	case (CTC_PHASE_CORRECT_PWM_CLEAR_OC0_ON_UPCOUNTING_SET_ON_DOWNCOUNTING): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11101111; break;
	case (CTC_PHASE_CORRECT_PWM_SET_OC0_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING): TCCR0 &= CTC_OUTPUT_MASK; TCCR0 |= 0b11111111; break;
	}

	TCCR0 &= TCCR0_MASK;
	TCCR0 |= Copy_EnumPrescaler;
}

void TIMER0_VidSetTimerValue(u8 Copy_u8Value)
{
	TCNT0 &= 0b00000000;

	TCNT0 |= Copy_u8Value;
}

void TIMER0_VidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0 &= 0b00000000;

	OCR0 |= Copy_u8Value;
}

/*Post Build Configuration for Timer0 */
void TIMER1_VidInit(void)
{

}

/*PreBuild Configuration for Timer2 */
void TIMER2_VidInit(void)
{
	/*Choose Timer0 mode*/
#if TIMER2_MODE == NORMAL_MODE
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER2_MODE == PWM_PHASE_CORRECT_MODE
	  SET_BIT(TCCR0 , TCCR0_WGM00);
	  CLR_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER2_MODE == CTC_MODE
	  CLR_BIT(TCCR0 , TCCR0_WGM00);
	  SET_BIT(TCCR0 , TCCR0_WGM01);

#elif TIMER2_MODE == PWM_FAST_MODE
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

#else
#error "Wrong TIMER2_MODE Configuration option"
#endif

#if TIMER2_COMPARE_OUTPUT_MODE == NORMAL_OC2_DISCONNECTED
	TCCR2 &= CTC_OUTPUT_MASK;

#elif TIMER2_COMPARE_OUTPUT_MODE == NON_PWM_TOGGLE_OC2_ON_CTC
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11011111;

#elif TIMER2_COMPARE_OUTPUT_MODE == NON_PWM_CLEAR_OC2_ON_CTC
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11101111;

#elif TIMER2_COMPARE_OUTPUT_MODE == NON_PWM_SET_OC2_ON_CTC
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11111111;

#elif TIMER2_COMPARE_OUTPUT_MODE == FAST_PWM_CLEAR_OC2_ON_CTC_SET_ON_TOP
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11101111;

#elif TIMER2_COMPARE_OUTPUT_MODE == FAST_PWM_SET_OC2_ON_CTC_CLEAR_ON_TOP
	  TCCR2 &= CTC_OUTPUT_MASK;
      TCCR2 |= 0b11111111;

#elif TIMER2_COMPARE_OUTPUT_MODE == PHASE_CORRECT_PWM_CLEAR_OC2_ON_UPCOUNTING_SET_ON_DOWNCOUNTING
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11101111;

#elif TIMER2_COMPARE_OUTPUT_MODE == PHASE_CORRECT_PWM_SET_OC2_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
	  TCCR2 &= CTC_OUTPUT_MASK;
	  TCCR2 |= 0b11111111;

#else
#error "Wrong TIMER2_COMPARE_OUTPUT_MODE Configuration option"
#endif

	/*Set Prescaler*/
	TCCR2 &= TCCR2_MASK;
	TCCR2 |= TIMER_PRESCALER;
}

/*Post Build Configuration for Timer2 */

void TIMER2_VidTimerInit(TIMER_MODES_TYPE Copy_EnumMode , TIMER_PRESCALER_TYPE Copy_EnumPrescaler , TIMER2_CTC_MODE_TYPE Copy_CTC_Modes)
{
	switch(Copy_EnumMode)
	{
	case (NORMAL) : CLR_BIT(TCCR0 , TCCR0_WGM00); CLR_BIT(TCCR0 , TCCR0_WGM01); break;
	case (PWM_PHASE_CORRECT) : SET_BIT(TCCR0 , TCCR0_WGM00); CLR_BIT(TCCR0 , TCCR0_WGM01); break;
	case (CTC) : CLR_BIT(TCCR0 , TCCR0_WGM00); SET_BIT(TCCR0 , TCCR0_WGM01); break;
	case (PWM_FAST) : SET_BIT(TCCR0 , TCCR0_WGM00); SET_BIT(TCCR0 , TCCR0_WGM01); break;
	}

	switch(Copy_CTC_Modes)
	{
	case (OC2_DISCONNECTED) : TCCR2 &= CTC_OUTPUT_MASK; break;
	case (CTC_NON_PWM_TOGGLE_OC2_ON_CTC) : TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11011111; break;
	case (CTC_NON_PWM_CLEAR_OC2_ON_CTC): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11101111; break;
	case (CTC_NON_PWM_SET_OC2_ON_CTC): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11111111; break;
	case (CTC_FAST_PWM_CLEAR_OC2_ON_CTC_SET_ON_TOP): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11101111; break;
	case (CTC_FAST_PWM_SET_OC2_ON_CTC_CLEAR_ON_TOP): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11111111; break;
	case (CTC_PHASE_CORRECT_PWM_CLEAR_OC2_ON_UPCOUNTING_SET_ON_DOWNCOUNTING): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11101111; break;
	case (CTC_PHASE_CORRECT_PWM_SET_OC2_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING): TCCR2 &= CTC_OUTPUT_MASK; TCCR2 |= 0b11111111; break;
	}

	TCCR2 &= TCCR2_MASK;
	TCCR2 |= Copy_EnumPrescaler;
}

void TIMER2_VidSetTimerValue(u8 Copy_u8Value)
{
	TCNT2 &= 0b00000000;

	TCNT2 |= Copy_u8Value;
}

void TIMER2_VidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR2 &= 0b00000000;

	OCR2 |= Copy_u8Value;
}



