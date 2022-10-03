/**************************************************************************************************************************/
/**************************************************************************************************************************/
/***********************************  Author: Ali Ahmed   *****************************************************************/
/***********************************  Layer:  MCAL        *****************************************************************/
/***********************************  SWC:    EXI_Driver  *****************************************************************/
/***********************************  Version:1.00        *****************************************************************/
/***********************************  Micro:  Atmega32    *****************************************************************/
/**************************************************************************************************************************/
/**************************************************************************************************************************/

# ifndef EXI_INTERFACE_H
# define EXI_INTERFACE_H

//Initialization function of External Interrupt 0
void EXI0_VidINT0Init(void);

//Initialization function of External Interrupt 1
void EXI1_VidINT1Init(void);

//Initialization function of External Interrupt 2
void EXI2_VidINT2Init(void);

//Initialization function of External Interrupt 0
void EXI0_VidInit(u8 Copy_u8INT0SenseControl);

//Initialization function of External Interrupt 1
void EXI1_VidInit(u8 Copy_u8INT1SenseControl);

//Initialization function of External Interrupt 2
void EXI2_VidInit(u8 Copy_u8INT2SenseControl);

void EXI0_VidEnable(void);

void EXI1_VidEnable(void);

void EXI2_VidEnable(void);

void EXI0_VidDisable(void);

void EXI1_VidDisable(void);

void EXI2_VidDisable(void);

u8 EXI_u8INT0SetCallBack(void (*Copy_VidPtrINT0Func)(void));

u8 EXI_u8INT1SetCallBack(void (*Copy_VidPtrINT1Func)(void));

u8 EXI_u8INT2SetCallBack(void (*Copy_VidPtrINT2Func)(void));

# endif
