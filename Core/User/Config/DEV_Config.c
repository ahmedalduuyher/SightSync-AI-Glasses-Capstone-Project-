/******************************************************************************
**************************Hardware interface layer*****************************
* | file      		:	DEV_Config.c
* |	version			:	V1.0
* | date			:	2020-06-17
* | function		:	Provide the hardware underlying interface	
******************************************************************************/
#include "DEV_Config.h"
#include "stm32f0xx_hal_i2c.h"
#include "Soft_IIC.h"
#include <stdio.h>		//printf()
#include <string.h>
#include <stdlib.h>

/********************************************************************************
function:	System Init
note:
	Initialize the communication method
********************************************************************************/
uint8_t System_Init(void)
{
#if USE_SPI_4W
	printf("USE_SPI_4W\r\n");
#elif USE_IIC
	printf("USE_IIC\r\n");
	OLED_CS_0;
	OLED_DC_1;
	//DC = 0,1 >> Address = 0x3c,0x3d 
#elif USE_IIC_SOFT
	printf("USEI_IIC_SOFT\r\n");
	OLED_CS_0;
	OLED_DC_1;
	iic_init();
	
#endif
  return 0;
}

void System_Exit(void)
{

}
/********************************************************************************
function:	Hardware interface
note:
	SPI4W_Write_Byte(value) : 
		HAL library hardware SPI
		Register hardware SPI
		Gpio analog SPI
	I2C_Write_Byte(value, cmd):
		HAL library hardware I2C
********************************************************************************/


void I2C_Write_Byte(uint8_t value, uint8_t Cmd)
{
    int Err;
    uint8_t W_Buf[2] ;
    W_Buf[0] = Cmd;
    W_Buf[1] = value;
    if(HAL_I2C_Master_Transmit(&hi2c1, (I2C_ADR << 1) | 0X00, W_Buf, 2, 0x10) != HAL_OK) {
        Err++;
        if(Err == 1000) {
            printf("send error\r\n");
            return ;
        }
    }
}

/********************************************************************************
function:	Delay function
note:
	Driver_Delay_ms(xms) : Delay x ms
	Driver_Delay_us(xus) : Delay x us
********************************************************************************/
void Driver_Delay_ms(uint32_t xms)
{
    HAL_Delay(xms);
}

void Driver_Delay_us(uint32_t xus)
{
    int j;
    for(j=xus; j > 0; j--);
}
