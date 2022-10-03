/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    DIO_Driver  *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
# include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
# include "DIO_register.h"
# include "DIO_interface.h"

void DIO_VidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	if (Copy_u8Direction == OUTPUT)
		{
			switch (Copy_u8Port)
			{
			case (PORT_A): DDRA = 0XFF;break;
			case (PORT_B): DDRB = 0XFF;break;
			case (PORT_C): DDRC = 0XFF;break;
			case (PORT_D): DDRD = 0XFF;break;
			}
         }
    else if (Copy_u8Direction == INPUT)
		{
            switch (Copy_u8Port)
			{
			case (PORT_A): DDRA = 0x00;break;
			case (PORT_B): DDRB = 0x00;break;
			case (PORT_C): DDRC = 0x00;break;
			case (PORT_D): DDRD = 0x00;break;
			}
		}
}

void DIO_VidSetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	switch (Copy_u8Port)
				{
				case (PORT_A): PORTA = Copy_u8Value;break;
				case (PORT_B): PORTB = Copy_u8Value;break;
				case (PORT_C): PORTC = Copy_u8Value;break;
				case (PORT_D): PORTD = Copy_u8Value;break;
				}
}

u8 DIO_u8GetPortValue(u8 Copy_u8Port)
{
	u32 value;
	    switch(Copy_u8Port)
				{
				case(PORT_A):value = PINA;break;
				case(PORT_B):value = PINB;break;
				case(PORT_C):value = PINC;break;
				case(PORT_D):value = PIND;break;
				}

		return value;
}


void DIO_VidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	if (Copy_u8Direction == OUTPUT)
	{
		switch (Copy_u8Port)
		{
		case (PORT_A): SET_BIT(DDRA,Copy_u8Pin);break;
		case (PORT_B): SET_BIT(DDRB,Copy_u8Pin);break;
		case (PORT_C): SET_BIT(DDRC,Copy_u8Pin);break;
		case (PORT_D): SET_BIT(DDRD,Copy_u8Pin);break;
		}
	}
	else if (Copy_u8Direction == INPUT)
	{
		switch (Copy_u8Port)
		{
		case (PORT_A): CLR_BIT(DDRA,Copy_u8Pin);break;
		case (PORT_B): CLR_BIT(DDRB,Copy_u8Pin);break;
		case (PORT_C): CLR_BIT(DDRC,Copy_u8Pin);break;
		case (PORT_D): CLR_BIT(DDRD,Copy_u8Pin);break;
		}
	}
}

void DIO_VidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	if (Copy_u8Value == HIGH)
		{
			switch (Copy_u8Port)
			{
			case (PORT_A): SET_BIT(PORTA,Copy_u8Pin);break;
			case (PORT_B): SET_BIT(PORTB,Copy_u8Pin);break;
			case (PORT_C): SET_BIT(PORTC,Copy_u8Pin);break;
			case (PORT_D): SET_BIT(PORTD,Copy_u8Pin);break;
			}
		}
		else if (Copy_u8Value == LOW)
		{
			switch (Copy_u8Port)
			{
			case (PORT_A): CLR_BIT(PORTA,Copy_u8Pin);break;
			case (PORT_B): CLR_BIT(PORTB,Copy_u8Pin);break;
			case (PORT_C): CLR_BIT(PORTC,Copy_u8Pin);break;
			case (PORT_D): CLR_BIT(PORTD,Copy_u8Pin);break;
			}
		}
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin)
{
	   u32 value;
	
		switch(Copy_u8Port)
		    {
			case(PORT_A): value = GET_BIT(PINA,Copy_u8Pin);break;
			case(PORT_B): value = GET_BIT(PINB,Copy_u8Pin);break;
			case(PORT_C): value = GET_BIT(PINC,Copy_u8Pin);break;
			case(PORT_D): value = GET_BIT(PIND,Copy_u8Pin);break;
			}
		
	return value;
}

