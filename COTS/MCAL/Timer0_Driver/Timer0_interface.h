/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Timer0      *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef TIMER0_INTERFACE_H
# define TIMER0_INTERFACE_H

/*PostBuild Configuration for Timer0 */
typedef enum
{
	NORMAL,
	PWM_PHASE_CORRECT,
	CTC ,
	PWM_FAST
}TIMER_MODES_TYPE;

typedef enum
{
	OC0_DISCONNECTED,
	CTC_NON_PWM_TOGGLE_OC0_ON_CTC,
	CTC_NON_PWM_CLEAR_OC0_ON_CTC,
	CTC_NON_PWM_SET_OC0_ON_CTC,
	CTC_FAST_PWM_CLEAR_OC0_ON_CTC_SET_ON_TOP,
	CTC_FAST_PWM_SET_OC0_ON_CTC_CLEAR_ON_TOP,
	CTC_PHASE_CORRECT_PWM_CLEAR_OC0_ON_UPCOUNTING_SET_ON_DOWNCOUNTING,
	CTC_PHASE_CORRECT_PWM_SET_OC0_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
}TIMER0_CTC_MODE_TYPE;


typedef enum
{
	TIMER0_STOP,
	DIVIDED_BY_1,
	DIVIDED_BY_8,
	DIVIDED_BY_64,
	DIVIDED_BY_256,
	DIVIDED_BY_1024,
	EXTERNAL1_FALLING_EDGE,
	EXTERNAL1_RISING_EDGE
}TIMER_PRESCALER_TYPE;

typedef enum
{
	NORMAL_WAVE_MODE,
	PWM_PHASE_CORRECT_8BIT,
	PWM_PHASE_CORRECT_9BIT,
	PWM_PHASE_CORRECT_10BIT,
	CTC_OCR1A,
	FAST_PWM_8BIT,
	FAST_PWM_9BIT,
	FAST_PWM_10BIT,
	PWM_PHASE_FREQUANCY_CORRECT_ICR1,
    PWM_PHASE_FREQUANCY_CORRECT_OCR1A,
	PWM_PHASE_CORRECT_ICR1,
	PWM_PHASE_CORRECT_OCR1A,
	CTC_ICR1,
	RESERVED,
	FAST_PWM_OCR1,
	FAST_PWM_OCR1A,
}TIMER1_MODES_TYPE;



typedef enum
{
	OC1A_B_DISCONNECTED,
	CTC_NON_PWM_TOGGLE_OC1A_B_ON_CTC,
	CTC_NON_PWM_CLEAR_OC1A_B_ON_CTC,
	CTC_NON_PWM_SET_OC1A_B_ON_CTC,
	CTC_FAST_PWM_TOGGLE_OC1A_ON_CTC,
	CTC_FAST_PWM_CLEAR_OC1A_B_ON_CTC_SET_ON_TOP,
	CTC_FAST_PWM_SET_OC1A_B_ON_CTC_CLEAR_ON_TOP,
	CTC_PHASE_CORRECT_TOGGLE_OC1A_ON_CTC,
	CTC_PHASE_CORRECT_CLEAR_OC1A_B_ON_CTC_SET_ON_TOP,
	CTC_PHASE_CORRECT_SET_OC1A_B_ON_CTC_CLEAR_ON_TOP,
}TIMER1_CTC_MODE_TYPE;

/*PostBuild Configuration for Timer2 */
typedef enum
{
	OC2_DISCONNECTED,
	CTC_NON_PWM_TOGGLE_OC2_ON_CTC,
	CTC_NON_PWM_CLEAR_OC2_ON_CTC,
	CTC_NON_PWM_SET_OC2_ON_CTC,
	CTC_FAST_PWM_CLEAR_OC2_ON_CTC_SET_ON_TOP,
	CTC_FAST_PWM_SET_OC2_ON_CTC_CLEAR_ON_TOP,
	CTC_PHASE_CORRECT_PWM_CLEAR_OC2_ON_UPCOUNTING_SET_ON_DOWNCOUNTING,
	CTC_PHASE_CORRECT_PWM_SET_OC2_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
}TIMER2_CTC_MODE_TYPE;





void TIMER0_VidInit(void);

u8 TIMER0_u8SetCallBack(void (*Copy_VidPtrCallBackFunc)(void));

void TIMER0_VidTimerInit(TIMER_MODES_TYPE Copy_EnumMode , TIMER_PRESCALER_TYPE Copy_EnumPrescaler , TIMER0_CTC_MODE_TYPE Copy_CTC_Modes);

void TIMER0_VidSetCompareMatchValue(u8 Copy_u8Value);

void TIMER0_VidSetTimerValue(u8 Copy_u8Value);


void TIMER1_VidSetTimerValue(u16 Copy_u16Value);

u16 TIMER1_u16ReadTimerValue(void);

void TIMER1_VidInit(void);

void TIMER2_VidTimerInit(TIMER_MODES_TYPE Copy_EnumMode , TIMER_PRESCALER_TYPE Copy_EnumPrescaler , TIMER2_CTC_MODE_TYPE Copy_CTC_Modes);

void TIMER2_VidSetCompareMatchValue(u8 Copy_u8Value);

void TIMER2_VidSetTimerValue(u8 Copy_u8Value);

#endif
