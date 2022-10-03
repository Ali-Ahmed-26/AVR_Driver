/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    UART        *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "UART_register.h"
#include "UART_configuration.h"
#include "UART_private.h"
#include "UART_interface.h"


void UART_VidInit(BAUD_RATE Copy_BaudRate , TRANSMITTED_SPEED Copy_TRANSMITTED_SPEED)
{
	u8 Local_u8UCSRCValue =0;
	/*set to write to UCSRC register*/
	SET_BIT(Local_u8UCSRCValue , UCSRC_URSEL);

#if USART_MODE == ASYNCHRONOUS_OPERATION
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UMSEL);
#elif USART_MODE == SYNCHRONOUS_OPERATION
	SET_BIT(Local_u8UCSRCValue , UCSRC_UMSEL);
#else
#error "Wrong USART_MODE Configuration option"
#endif

#if PARITY_MODE == DISABLED_PARITY
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UPM1);
#elif PARITY_MODE == EVEN_PARITY
	CLR_BIT(Local_u8UCSRCValue, UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UPM1);
#elif PARITY_MODE == ODD_PARITY
	SET_BIT(Local_u8UCSRCValue , UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UPM1);
#else
#error "Wrong PARITY_MODE Configuration option"
#endif

#if STOP_BIT_MODE == STOP_1BIT
	CLR_BIT(Local_u8UCSRCValue , UCSRC_USBS);
#elif STOP_BIT_MODE == STOP_2BIT
	SET_BIT(Local_u8UCSRCValue , UCSRC_USBS);
#else
#error "Wrong STOP_BIT_MODE Configuration option"
#endif

#if CHARACTER_SIZE == CHARACTER_5_BIT
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif CHARACTER_SIZE == CHARACTER_6_BIT
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif CHARACTER_SIZE == CHARACTER_7_BIT
	CLR_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif CHARACTER_SIZE == CHARACTER_8_BIT
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	CLR_BIT(UCSRB , UCSRB_UCSZ2);
#elif CHARACTER_SIZE == CHARACTER_9_BIT
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	SET_BIT(UCSRB , UCSRB_UCSZ2);
#else
#error "Wrong CHARACTER_SIZE Configuration option"
#endif

#if SYNCHRONOUS_clock == TRANSMITTED_RISING_EDGE_RECEIVED_FALLING_EDGE
	    CLR_BIT(Local_u8UCSRCValue , UCSRC_UCPOL);
#elif SYNCHRONOUS_clock == TRANSMITTED_FALLING_EDGE_RECEIVED_RISING_EDGE
	    SET_BIT(Local_u8UCSRCValue , UCSRC_UCPOL);
#else
#error "Wrong SYNCHRONOUS_clock Configuration option"
#endif

	    UCSRC = Local_u8UCSRCValue;


#if CLOCK_FREQUANCY == FREQUANCY_8_MHZ
	   if(Copy_TRANSMITTED_SPEED == U1X)
	   {
		   CLR_BIT(UCSRA , UCSRA_U2X);

	    switch(Copy_BaudRate)
	    {
	    case (BAUD_RATE_2400) : UBRRL = 207; break;
	    case (BAUD_RATE_4800) : UBRRL = 103; break;
	    case (BAUD_RATE_9600) : UBRRL = 51; break;
	    case (BAUD_RATE_14_4K): UBRRL = 34; break;
	    case (BAUD_RATE_19_2K): UBRRL = 25; break;
	    case (BAUD_RATE_28_8K): UBRRL = 16; break;
	    case (BAUD_RATE_38_4K): UBRRL = 12; break;
	    case (BAUD_RATE_57_6K): UBRRL = 8; break;
	    case (BAUD_RATE_76_8K): UBRRL = 6; break;
	    case (BAUD_RATE_115_2K): UBRRL = 3;break;
	    case (BAUD_RATE_230_4K): UBRRL = 1;break;
	    case (BAUD_RATE_250K)  : UBRRL = 1;break;
	    case (BAUD_RATE_0_5M)  : UBRRL = 0;break;
	    }
	   }
	   else if(Copy_TRANSMITTED_SPEED == U2X)
	   {
		   SET_BIT(UCSRA , UCSRA_U2X);

		   switch(Copy_BaudRate)
		   	    {
		   	    case (BAUD_RATE_2400) : UBRRL = 416; break;
		   	    case (BAUD_RATE_4800) : UBRRL = 207; break;
		   	    case (BAUD_RATE_9600) : UBRRL = 103; break;
		   	    case (BAUD_RATE_14_4K): UBRRL = 68; break;
		   	    case (BAUD_RATE_19_2K): UBRRL = 51; break;
		   	    case (BAUD_RATE_28_8K): UBRRL = 34; break;
		   	    case (BAUD_RATE_38_4K): UBRRL = 25; break;
		   	    case (BAUD_RATE_57_6K): UBRRL = 16; break;
		   	    case (BAUD_RATE_76_8K): UBRRL = 12; break;
		   	    case (BAUD_RATE_115_2K): UBRRL = 8;break;
		   	    case (BAUD_RATE_230_4K): UBRRL = 3;break;
		   	    case (BAUD_RATE_250K)  : UBRRL = 3;break;
		   	    case (BAUD_RATE_0_5M)  : UBRRL = 1;break;
		   	    case (BAUD_RATE_1M)    : UBRRL = 0;break;
		   	    }
	   }
#else
#error "Wrong CLOCK_FREQUANCY Configuration option"
#endif

#if TRANSMITTER_MODE == ENABLED
	   SET_BIT(UCSRB , UCSRB_TXEN);
#elif TRANSMITTER_MODE == DISABLED
	   CLR_BIT(UCSRB , UCSRB_TXEN);
#else
#error "Wrong TRANSMITTER_MODE Configuration option"
#endif

#if RECEIVER_MODE == ENABLED
	   SET_BIT(UCSRB , UCSRB_RXEN);
#elif RECEIVER_MODE == DISABLED
	   CLR_BIT(UCSRB , UCSRB_RXEN);
#else
#error "Wrong RECEIVER_MODE Configuration option"
#endif
}

void UART_VidSend(u8 Copy_u8Data)
{
   while((GET_BIT(UCSRA , UCSRA_UDRE))==0 );

   UDR = Copy_u8Data;
}

u8 UART_VidRecevie(void)
{
	while((GET_BIT(UCSRA , UCSRA_RXC))==0 );

	return UDR;
}

