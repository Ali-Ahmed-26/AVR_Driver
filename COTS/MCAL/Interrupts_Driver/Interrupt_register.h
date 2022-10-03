/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    Interrupt   *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef INTERRUPTS_REGISTER_H
# define INTERRUPTS_REGISTER_H

//Interrupt 0 Register*************************************
//External interrupt 0 Enabled
# define GICR          *((volatile u8*)0x5B)
# define GICR_INT0     6
//External interrupt 0 Enabled
# define GICR_INT1     7
//External interrupt 2 Enabled
# define GICR_INT2     5
//**********************************************************

//Timer0 Interrupt Register*************************************
# define TIMSK          *((volatile u8*)0x59)
//Output Compare Match Interrupt Enable
# define TIMSK_OCIE0    1
//Timer/Counter0 Overflow Interrupt Enable
# define TIMSK_TOIE0    0
//Timer/Counter1 Overflow Interrupt Enable
# define TIMSK_TOIE1    2
//Timer/Counter1, Input Capture Interrupt Enable
# define TIMSK_TICIE1   5
//Timer/Counter1, Output Compare A Match Interrupt Enable
# define TIMSK_OCIE1A   4
//Timer/Counter1, Output Compare B Match Interrupt Enable
# define TIMSK_OCIE1B   3
//Timer/Counter2 Overflow Interrupt Enable
# define TIMSK_TOIE2    6
//Timer/Counter2,Output Compare Match Interrupt Enable
# define TIMSK_OCIE2    7
//**********************************************************

//ADC Interrupt Register*************************************
# define ADCSRA          *((volatile u8*)0x26)
//ADC Interrupt Enable
# define ADCSRA_ADIE     3
# endif
