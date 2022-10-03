
#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "D:\AVR_WS\COTS\MCAL\DIO_Driver\DIO_interface.h"
#include "D:\AVR_WS\COTS\MCAL\UART_Driver\UART_interface.h"

void main(void)
{
	u8 Local_u8Data=0;

	DIO_VidSetPinDirection(PORT_C,PIN_0,OUTPUT);
	UART_VidInit(BAUD_RATE_9600, U1X);

	while(1)
	{
		Local_u8Data = UART_VidRecevie();

		switch(Local_u8Data)
		{
		case ('1'):DIO_VidSetPinValue(PORT_C,PIN_0,HIGH);break;
		case ('5'):DIO_VidSetPinValue(PORT_C,PIN_0,LOW);break;
		}

		UART_VidSend('A');
	}
}
