/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    UART        *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef UART_CONFIGURATION_H
# define UART_CONFIGURATION_H

/*Options:
           1- ASYNCHRONOUS_OPERATION
           2- SYNCHRONOUS_OPERATION
                                            */
#define USART_MODE               ASYNCHRONOUS_OPERATION

/*Options:
           1- DISABLED_PARITY
           2- EVEN_PARITY
           3- ODD_PARITY
                                            */
#define PARITY_MODE               DISABLED_PARITY

/*Options:
           1- STOP_1BIT
           2- STOP_2BIT
                                            */
#define STOP_BIT_MODE               STOP_1BIT

/*Options:
           1- CHARACTER_5_BIT
           2- CHARACTER_6_BIT
           3- CHARACTER_7_BIT
           4- CHARACTER_8_BIT
           5- CHARACTER_9_BIT
                                            */
#define CHARACTER_SIZE               CHARACTER_8_BIT

/* This options used for synchronous mode only
 * Options:
           1- TRANSMITTED_RISING_EDGE_RECEIVED_FALLING_EDGE
           2- TRANSMITTED_FALLING_EDGE_RECEIVED_RISING_EDGE
                                            */
#define SYNCHRONOUS_clock             TRANSMITTED_RISING_EDGE_RECEIVED_FALLING_EDGE

/*Options:
           1- FREQUANCY_8_MHZ

                                            */
#define CLOCK_FREQUANCY               FREQUANCY_8_MHZ

/*Options:
           1- ENABLED
           2- DISABLED

                                            */
#define TRANSMITTER_MODE               ENABLED

/*Options:
           1- ENABLED
           2- DISABLED

                                            */
#define RECEIVER_MODE                 ENABLED

#endif
