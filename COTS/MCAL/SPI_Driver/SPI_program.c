/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    SPI         *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

#include "D:\AVR_WS\COTS\Lib\STD_TYPES.h"
#include "D:\AVR_WS\COTS\Lib\BIT_MATH.h"
#include "SPI_register.h"
#include "SPI_configuration.h"
#include "SPI_private.h"
#include "SPI_interface.h"

void SPI_VidInitMaster(void)
{
  /*Set SPI Master */
#if SPI_MASTER_ENABLE == ENABLED
	    SET_BIT(SPCR , SPCR_MSTR);

#elif SPI_MASTER_ENABLE == DISABLED
	    CLR_BIT(SPCR , SPCR_MSTR);

#else
#error "Wrong SPI_MASTER_ENABLE Configuration option"
#endif

	    /*Set SPI Send firstly*/
#if SPI_CLOCK_POLARITY == LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE
        SET_BIT(SPCR , SPCR_CPHA);

#elif SPI_CLOCK_POLARITY == LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP
        CLR_BIT(SPCR , SPCR_CPHA);

#else
#error "Wrong SPI_CLOCK_POLARITY Configuration option"
#endif

        /*Set SPI Send at Rising edge*/
#if SPI_CLOCK_PHASE == LEADING_EDGE_RISING_TRAILING_EDGE_FALLING
        CLR_BIT(SPCR , SPCR_CPOL);

#elif SPI_CLOCK_PHASE == LEADING_EDGE_FALLING_TRAILING_EDGE_RISING
        SET_BIT(SPCR , SPCR_CPOL);

#else
#error "Wrong SPI_CLOCK_PHASE Configuration option"
#endif

     /*Set Transfer Data from LSB */
#if SPI_DATA_ORDER == LSB_TRANSMITTED
	    SET_BIT(SPCR , SPCR_DORD);

#elif SPI_DATA_ORDER == MSB_TRANSMITTED
	    CLR_BIT(SPCR , SPCR_DORD);

#else
#error "Wrong SPI_DATA_ORDER Configuration option"
#endif

	/*Set Oscillator Frequency */
#if SPI_SCK == FREQUANCY_DIVIDE_BY_4
        CLR_BIT(SPCR , SPCR_SPR0);
        CLR_BIT(SPCR , SPCR_SPR1);
        CLR_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_16
        SET_BIT(SPCR , SPCR_SPR0);
        CLR_BIT(SPCR , SPCR_SPR1);
        CLR_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_64
        CLR_BIT(SPCR , SPCR_SPR0);
        SET_BIT(SPCR , SPCR_SPR1);
        CLR_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_128
        SET_BIT(SPCR , SPCR_SPR0);
        SET_BIT(SPCR , SPCR_SPR1);
        CLR_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_2
        CLR_BIT(SPCR , SPCR_SPR0);
        CLR_BIT(SPCR , SPCR_SPR1);
        SET_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_8
        SET_BIT(SPCR , SPCR_SPR0);
        CLR_BIT(SPCR , SPCR_SPR1);
        SET_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_32
        CLR_BIT(SPCR , SPCR_SPR0);
        SET_BIT(SPCR , SPCR_SPR1);
        SET_BIT(SPSR , SPSR_SPI2X);

#elif SPI_SCK == FREQUANCY_DIVIDE_BY_64
        SET_BIT(SPCR , SPCR_SPR0);
        SET_BIT(SPCR , SPCR_SPR1);
        SET_BIT(SPSR , SPSR_SPI2X);

#else
#error "Wrong SPI_SCK Configuration option"
#endif

   /*Set SPI Enabled*/
#if SPI_ENABLE == ENABLED
	    SET_BIT(SPCR , SPCR_SPE);

#elif SPI_ENABLE == DISABLED
	    CLR_BIT(SPCR , SPCR_SPE);
#else
#error "Wrong SPI_ENABLE Configuration option"
#endif

}

void SPI_VidInitSlave(void)
{
  /*Set SPI Slave */
CLR_BIT(SPCR , SPCR_MSTR);

	    /*Set SPI Send firstly*/
#if SPI_CLOCK_POLARITY == LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE
        SET_BIT(SPCR , SPCR_CPHA);

#elif SPI_CLOCK_POLARITY == LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP
        CLR_BIT(SPCR , SPCR_CPHA);

#else
#error "Wrong SPI_CLOCK_POLARITY Configuration option"
#endif

        /*Set SPI Send at Rising edge*/
#if SPI_CLOCK_PHASE == LEADING_EDGE_RISING_TRAILING_EDGE_FALLING
        CLR_BIT(SPCR , SPCR_CPOL);

#elif SPI_CLOCK_PHASE == LEADING_EDGE_FALLING_TRAILING_EDGE_RISING
        SET_BIT(SPCR , SPCR_CPOL);

#else
#error "Wrong SPI_CLOCK_PHASE Configuration option"
#endif

     /*Set Transfer Data from LSB */
#if SPI_DATA_ORDER == LSB_TRANSMITTED
	    SET_BIT(SPCR , SPCR_DORD);

#elif SPI_DATA_ORDER == MSB_TRANSMITTED
	    CLR_BIT(SPCR , SPCR_DORD);

#else
#error "Wrong SPI_DATA_ORDER Configuration option"
#endif

   /*Set SPI Enabled*/
#if SPI_ENABLE == ENABLED
	    SET_BIT(SPCR , SPCR_SPE);

#elif SPI_ENABLE == DISABLED
	    CLR_BIT(SPCR , SPCR_SPE);
#else
#error "Wrong SPI_ENABLE Configuration option"
#endif

}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send the data*/
	SPDR = Copy_u8Data;

	/*wait (busy waiting) until transfer complete*/
	while((GET_BIT(SPSR , SPSR_SPIF))==0);

	/*Get the exchange data*/
		return SPDR;
}

