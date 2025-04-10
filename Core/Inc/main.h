/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#ifndef HAL_SPI_MODULE_ENABLED
typedef struct {
} SPI_HandleTypeDef;
#endif

extern SPI_HandleTypeDef hspi1;

extern UART_HandleTypeDef husart1;;

extern I2C_HandleTypeDef hi2c1;

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define OLED_CS_Pin GPIO_PIN_5
#define OLED_CS_GPIO_Port GPIOA
#define OLED_DC_Pin GPIO_PIN_0
#define OLED_DC_GPIO_Port GPIOB
#define OLED_RST_Pin GPIO_PIN_1
#define OLED_RST_GPIO_Port GPIOB
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define IIC_SCL_SOFT_Pin GPIO_PIN_4
#define IIC_SCL_SOFT_GPIO_Port GPIOB
#define IIC_SDA_SOFT_Pin GPIO_PIN_7
#define IIC_SDA_SOFT_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
/* Private defines -----------------------------------------------------------*/
#define HC05_EN_PIN    GPIO_PIN_3
#define HC05_EN_PORT   GPIOA //A2
#define HC05_STATE_PIN GPIO_PIN_6
#define HC05_STATE_PORT GPIOA //A5

// ----------------- BLUETOOTH MODULE -----------------------
// D1 = TX
// D0 = RX
// HC05 VOLTAGE = 5V
// HC05 EN = A2
// HC05 STATE = A5

// ----------------- MICROPHONE -----------------------------

// SEL = GND
// LRCL = A3
// DOUT = A6
// BCLK = D13
// MICROPHONE VOLTAGE = 3.3v

// ---------------------- OLED ------------------------------
// OLED CS = A4
// OLED RST = D6
// OLED DC = D3
// IIC SCL = D12
// IIC SDA = D4
// OLED VOLTAGE = 3.3v

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
