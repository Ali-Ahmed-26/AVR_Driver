/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    UART        *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef UART_PRIVATE_H
# define UART_PRIVATE_H


#define SYNCHRONOUS_OPERATION                  1
#define ASYNCHRONOUS_OPERATION                  2

#define DISABLED_PARITY                         1
#define EVEN_PARITY                             2
#define ODD_PARITY                              3

#define STOP_1BIT                               1
#define STOP_2BIT                               2

#define CHARACTER_5_BIT                         1
#define CHARACTER_6_BIT                         2
#define CHARACTER_7_BIT                         3
#define CHARACTER_8_BIT                         4
#define CHARACTER_9_BIT                         5

#define TRANSMITTED_RISING_EDGE_RECEIVED_FALLING_EDGE     1
#define TRANSMITTED_FALLING_EDGE_RECEIVED_RISING_EDGE     2

#define FREQUANCY_8_MHZ                        1

#define ENABLED                            1
#define DISABLED                           2



#endif
