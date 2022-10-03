/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    SPI         *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef SPI_CONFIGURATION_H
# define SPI_CONFIGURATION_H


/*Options:
           1- FREQUANCY_DIVIDE_BY_4
           2- FREQUANCY_DIVIDE_BY_16
           3- FREQUANCY_DIVIDE_BY_64
           4- FREQUANCY_DIVIDE_BY_128
           5- FREQUANCY_DIVIDE_BY_2
           6- FREQUANCY_DIVIDE_BY_8
           7- FREQUANCY_DIVIDE_BY_64
                                            */
#define SPI_SCK                            FREQUANCY_DIVIDE_BY_4

/*Options:
           1- LEADING_EDGE_SAMPLE_TRAILING_EDGE_SETUP
           2- LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE
                                            */
#define SPI_CLOCK_POLARITY               LEADING_EDGE_SETUP_TRAILING_EDGE_SAMPLE

/*Options:
           1- LEADING_EDGE_RISING_TRAILING_EDGE_FALLING
           2- LEADING_EDGE_FALLING_TRAILING_EDGE_RISING
                                            */
#define SPI_CLOCK_PHASE                 LEADING_EDGE_RISING_TRAILING_EDGE_FALLING

/*Options:
           1- LSB_TRANSMITTED
           2- MSB_TRANSMITTED
                                            */
#define SPI_DATA_ORDER                  LSB_TRANSMITTED

/*Options:
           1- ENABLED
           2- DISABLED
                                            */
#define SPI_ENABLE                      ENABLED

/*Options:
           1- ENABLED
           2- DISABLED
                                            */
#define SPI_MASTER_ENABLE                      ENABLED

#endif
