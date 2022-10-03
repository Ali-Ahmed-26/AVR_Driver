/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Timer0      *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef TIMER0_CONFIGURATION_H
# define TIMER0_CONFIGURATION_H

/*Options:
           1- NORMAL_MODE
           2- PWM_PHASE_CORRECT_MODE
           3- CTC_MODE
           4- PWM_FAST_MODE
                                            */
#define TIMER0_MODE               NORMAL_MODE

/*Options:
           1- NORMAL_OC0_DISCONNECTED
	       2- NON_PWM_TOGGLE_OC0_ON_CTC
	       3- NON_PWM_CLEAR_OC0_ON_CTC
	       4- NON_PWM_SET_OC0_ON_CTC
	       5- FAST_PWM_CLEAR_OC0_ON_CTC_SET_ON_TOP
	       6- FAST_PWM_SET_OC0_ON_CTC_CLEAR_ON_TOP
	       7- PHASE_CORRECT_PWM_CLEAR_OC0_ON_UPCOUNTING_SET_ON_DOWNCOUNTING
	       8- PHASE_CORRECT_PWM_SET_OC0_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
                                            */
#define TIMER0_COMPARE_OUTPUT_MODE      NORMAL_OC0_DISCONNECTED

/*Options:
           1- NO_CLOCK
           2- DIVIDE_BY_1
           3- DIVIDE_BY_8
           4- DIVIDE_BY_64
           5- DIVIDE_BY_256
           6- DIVIDE_BY_1024
           7- EXTERNAL_CLOCK_FALLING_EDGE
           8- EXTERNAL_CLOCK_RISING_EDGE
                                            */
#define TIMER_PRESCALER                DIVIDE_BY_8

/*Options:
           1- NORMAL_OC2_DISCONNECTED
	       2- NON_PWM_TOGGLE_OC2_ON_CTC
	       3- NON_PWM_CLEAR_OC2_ON_CTC
	       4- NON_PWM_SET_OC2_ON_CTC
	       5- FAST_PWM_CLEAR_OC2_ON_CTC_SET_ON_TOP
	       6- FAST_PWM_SET_OC2_ON_CTC_CLEAR_ON_TOP
	       7- PHASE_CORRECT_PWM_CLEAR_OC2_ON_UPCOUNTING_SET_ON_DOWNCOUNTING
	       8- PHASE_CORRECT_PWM_SET_OC2_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING
                                            */
#define TIMER2_COMPARE_OUTPUT_MODE      NORMAL_OC2_DISCONNECTED

/*Options:
           1- NORMAL_MODE
           2- PWM_PHASE_CORRECT_MODE
           3- CTC_MODE
           4- PWM_FAST_MODE
                                            */
#define TIMER2_MODE               NORMAL_MODE


#endif
