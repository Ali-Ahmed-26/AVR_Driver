/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Timer0      *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef TIMER0_PRIVATE_H
# define TIMER0_PRIVATE_H

#define NORMAL_MODE                        1
#define PWM_PHASE_CORRECT_MODE             2
#define CTC_MODE                           3
#define PWM_FAST_MODE                      4

#define NORMAL_OC0_DISCONNECTED                                               1
#define NON_PWM_TOGGLE_OC0_ON_CTC                                             2
#define NON_PWM_CLEAR_OC0_ON_CTC                                              3
#define NON_PWM_SET_OC0_ON_CTC                                                4
#define FAST_PWM_CLEAR_OC0_ON_CTC_SET_ON_TOP                                  5
#define FAST_PWM_SET_OC0_ON_CTC_CLEAR_ON_TOP                                  6
#define PHASE_CORRECT_PWM_CLEAR_OC0_ON_UPCOUNTING_SET_ON_DOWNCOUNTING         7
#define PHASE_CORRECT_PWM_SET_OC0_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING         8

#define NORMAL_OC2_DISCONNECTED                                               1
#define NON_PWM_TOGGLE_OC2_ON_CTC                                             2
#define NON_PWM_CLEAR_OC2_ON_CTC                                              3
#define NON_PWM_SET_OC2_ON_CTC                                                4
#define FAST_PWM_CLEAR_OC2_ON_CTC_SET_ON_TOP                                  5
#define FAST_PWM_SET_OC2_ON_CTC_CLEAR_ON_TOP                                  6
#define PHASE_CORRECT_PWM_CLEAR_OC2_ON_UPCOUNTING_SET_ON_DOWNCOUNTING         7
#define PHASE_CORRECT_PWM_SET_OC2_ON_UPCOUNTING_CLEAR_ON_DOWNCOUNTING         8

#define NO_CLOCK                          0
#define DIVIDE_BY_1                       1
#define DIVIDE_BY_8                       2
#define DIVIDE_BY_64                      3
#define DIVIDE_BY_256                     4
#define DIVIDE_BY_1024                    5
#define EXTERNAL_CLOCK_FALLING_EDGE       6
#define EXTERNAL_CLOCK_RISING_EDGE        7

#define TCCR0_MASK                         0b11111000

#define TCCR2_MASK                         0b11111000

#define CTC_OUTPUT_MASK                    0b11001111








#endif
