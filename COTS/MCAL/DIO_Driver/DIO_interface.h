/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    DIO_Driver  *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* define output and input values as a register direction */
#define OUTPUT         1  
#define INPUT          0
     
/* define high and low values as a register output value */ 	 
#define HIGH           1
#define LOW            0

/* define ports of micro_controller*/
#define PORT_A         1
#define PORT_B         2
#define PORT_C         3
#define PORT_D         4

/* define pins of ports */ 
#define PIN_0          0
#define PIN_1          1
#define PIN_2          2
#define PIN_3          3 
#define PIN_4          4
#define PIN_5          5
#define PIN_6          6
#define PIN_7          7

/* digital input/output functions */
void DIO_VidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);

void DIO_VidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

u8 DIO_u8GetPortValue(u8 Copy_u8Port);

void DIO_VidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);

void DIO_VidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin);


#endif
