/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    ADC         *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/


# ifndef ADC_CONFIGRATION_H
# define ADC_CONFIGRATION_H

/*Options:
           1- AREF
           2- AVCC
           3- Internal_Voltage
                                            */
#define VOLTAGE_REFERENCE       AVCC

/*Options:
           1- ENABLED
           2- DISABLED
                                            */
#define LEFT_ADJUST             ENABLED

/*Options:
           1- TWO
           2- FOUR
           3- EIGHT
           4- SIXTEEN
           5- THIRTY_TWO
           6- SIXTY_FOUR
           7- HUNDRED_TWENTY_EIGHT
                                            */
#define PRESCALER_DIV          HUNDRED_TWENTY_EIGHT

/*Options:
           1- ENABLED
           2- DISABLED
                                            */
#define ADC_INITIAL_STATE             ENABLED

/*Options:
           1- SINGLE_CONVERSTION
           2- AUTO_TRIGGER
                                            */
#define ADC_CONVERSION          SINGLE_CONVERSTION

/*Options:
           1- FREE_RUNNING_MODE
           2- ANALOG_COMPARATOR
           3- EXTERNAL_INTERRUPT0
           4- TIMER0_COMPARE_MATCH
           5- TIMER0_OVERFLOW
           6- TIMER_COMPARE_MATCH_B
           7- TIMER1_OVERFLOW
           8- TIMER1_CAPTURE_EVENT

                                            */
#define ADC_AUTO_TRIGGER_SOURCE          FREE_RUNNING_MODE

/*Options:
           1- ENABLED
           2- DISABLED
                                            */
#define ADC_INTERRUPT                    DISABLED

/*Options:
           1- SINGLE_ENDED
           2- DIFFERENTIAL
                                            */
#define ANALOG_CHANNEL_MODE              SINGLE_ENDED

/*Options:
           1- ADC0_CHANNEL0
           2- ADC1_CHANNEL1
           3- ADC2_CHANNEL2
           4- ADC3_CHANNEL3
           5- ADC4_CHANNEL4
           6- ADC5_CHANNEL5
           7- ADC6_CHANNEL6
           8- ADC7_CHANNEL7

                                            */
#define SINGLE_ENDED_INPUT               ADC0_CHANNEL0

/*Options:
           1- PD_ADC0_ND_ADC0_10x
           2- PD_ADC1_ND_ADC0_10x
           3- PD_ADC0_ND_ADC0_200x
           4- PD_ADC1_ND_ADC0_200x
           5- PD_ADC2_ND_ADC2_10x
           6- PD_ADC3_ND_ADC2_10x
           7- PD_ADC2_ND_ADC2_200x
           8- PD_ADC3_ND_ADC2_200x
           9- PD_ADC0_ND_ADC1_1x
          10- PD_ADC1_ND_ADC1_1x
          11- PD_ADC2_ND_ADC1_1x
          12- PD_ADC3_ND_ADC1_1x
          13- PD_ADC4_ND_ADC1_1x
          14- PD_ADC5_ND_ADC1_1x
          15- PD_ADC6_ND_ADC1_1x
          16- PD_ADC7_ND_ADC1_1x
          17- PD_ADC0_ND_ADC2_1x
          18- PD_ADC1_ND_ADC2_1x
          19- PD_ADC2_ND_ADC2_1x
          20- PD_ADC3_ND_ADC2_1x
          21- PD_ADC4_ND_ADC2_1x
                                       */
#define DIFFERENTIAL_INPUT            PD_ADC0_ND_ADC0_10x

/*Options:
           1- ADC_8_BITS
           2- ADC_10_BITS
                                            */
#define ADC_RESOLUTION                 ADC_8_BITS

#define ADC_u32TIMEOUT                 50000

# endif
