/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    ADC         *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/



# ifndef ADC_PRIVATE_H
# define ADC_PRIVATE_H

#define IDLE                      1
#define BUSY                      2
#define BUSY_FUNCTION             3

#define  AREF                     1
#define  AVCC                     2
#define  Internal_Voltage         3

#define  ENABLED                  1
#define  DISABLED                 2

#define PRESCALER_MASK            0b11111000
#define TWO                       0b11111001
#define FOUR                      0b11111010
#define EIGHT                     0b11111011
#define SIXTEEN                   0b11111100
#define THIRTY_TWO                0b11111101
#define SIXTY_FOUR                0b11111110
#define HUNDRED_TWENTY_EIGHT      0b11111111

#define SINGLE_CONVERSTION        1
#define AUTO_TRIGGER              2

#define AUTO_TRIGGER_MASK         0b00011111
#define FREE_RUNNING_MODE         0b00011111
#define ANALOG_COMPARATOR         0b00111111
#define EXTERNAL_INTERRUPT0       0b01011111
#define TIMER0_COMPARE_MATCH      0b01111111
#define TIMER0_OVERFLOW           0b10011111
#define TIMER_COMPARE_MATCH_B     0b10111111
#define TIMER1_OVERFLOW           0b11011111
#define TIMER1_CAPTURE_EVENT      0b11111111

#define  SINGLE_ENDED             1
#define  DIFFERENTIAL             2

#define ADC_INPUT_CHANNEL_MASK    0b11100000
#define ADC0_CHANNEL0             0b11100000
#define ADC1_CHANNEL1             0b11100001
#define ADC2_CHANNEL2             0b11100010
#define ADC3_CHANNEL3             0b11100011
#define ADC4_CHANNEL4             0b11100100
#define ADC5_CHANNEL5             0b11100101
#define ADC6_CHANNEL6             0b11100110
#define ADC7_CHANNEL7             0b11100111

#define PD_ADC0_ND_ADC0_10x       0b11101000


#define ADC_8_BITS                1
#define ADC_10_BITS               2

# endif
