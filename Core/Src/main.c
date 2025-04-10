/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>
#include "../User/Example/test.h"
#include "../User/OLED/OLED_0in96.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2S_HandleTypeDef hi2s1;
DMA_HandleTypeDef hdma_spi1_rx;
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

// Mic Code -------------------------------------------------------------------
//#define BUFFER_SIZE 700
//uint32_t i2sBuffer[BUFFER_SIZE]; // 2048 bytes 512 elements
//volatile uint8_t active_buffer = 0;

// HC05 Code -------------------------------------------------------------------
#define BUFFER_SIZE 100
uint8_t buffer0[BUFFER_SIZE + 1]; // +1 for null terminator
volatile uint16_t fillIndex = 0;


UBYTE *BlackImage;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2S1_Init(void);
static void MX_USART1_UART_Init(void);

/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s) {
//    HAL_UART_Transmit(&huart1, (uint8_t*)i2sBuffer, BUFFER_SIZE * 4, HAL_MAX_DELAY);
//    for(int i = 0; i < 600000; i++);
//}

/******************************************************************************
function:	Display the string
parameter:
    Xstart           ：X coordinate
    Ystart           ：Y coordinate
    pString          ：The first address of the English string to be displayed
    Font             ：A structure pointer that displays a character size
    Color_Foreground : Select the foreground color
    Color_Background : Select the background color
******************************************************************************/

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2S1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  if(System_Init() != 0) return -1;
      OLED_0in96_Init();
      Driver_Delay_ms(500);

      UWORD Imagesize = ((OLED_0in96_WIDTH%8==0)? (OLED_0in96_WIDTH/8): (OLED_0in96_WIDTH/8+1)) * OLED_0in96_HEIGHT;
      BlackImage = (UBYTE *)malloc(Imagesize);
      if(!BlackImage) {
          printf("Failed to apply for black memory...\r\n");
          return -1;
      }
      Paint_NewImage(BlackImage, OLED_0in96_WIDTH, OLED_0in96_HEIGHT, 90, BLACK);
      Paint_SelectImage(BlackImage);
      Driver_Delay_ms(500);
      Paint_Clear(BLACK);
      OLED_0in96_display(BlackImage);

      // Initialize data buffers
      memset(buffer0, 0, sizeof(buffer0));
      fillIndex = 0;
      uint16_t x_pos = 10;
      uint16_t y_pos = 0;
	/******************************************************************************
	function:	Display nummber
	parameter:
	    Xstart           ：X coordinate
	    Ystart           : Y coordinate
	    Nummber          : The number displayed
	    Font             ：A structure pointer that displays a character size
			Digit						 : Fractional width
	    Color_Foreground : Select the foreground color
	    Color_Background : Select the background color
	******************************************************************************/
	/******************************************************************************
	function:	Display the string
	parameter:
	    Xstart           ：X coordinate
	    Ystart           ：Y coordinate
	    pString          ：The first address of the English string to be displayed
	    Font             ：A structure pointer that displays a character size
	    Color_Foreground : Select the foreground color
	    Color_Background : Select the background color
	 ******************************************************************************/

  // Start I2S DMA once here (not inside the loop)
  //HAL_I2S_Receive_DMA(&hi2s1, (uint16_t*)i2sBuffer, BUFFER_SIZE); //1024 elements of 16 bit, but receiving 512 32 bit data = 1024 elements
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

      static uint32_t last_input_time = 0;
      static uint32_t screen_clear_timeout = 15000;
  while (1) {
      uint8_t byte;
      HAL_StatusTypeDef uart_status;
      fillIndex = 0;

      // 1. Check screen timeout first
      if (HAL_GetTick() - last_input_time >= screen_clear_timeout) {
          Paint_Clear(BLACK);
          OLED_0in96_display(BlackImage);
          x_pos = 10;
          y_pos = 0;
          last_input_time = HAL_GetTick();
      }

      // 2. Non-blocking UART receive with 100ms timeout
      do {
          uart_status = HAL_UART_Receive(&huart1, &byte, 1, 100); // 100ms timeout

          if(uart_status == HAL_OK) {
              buffer0[fillIndex++] = byte;
              last_input_time = HAL_GetTick(); // Reset timeout on received byte

              // Check termination conditions
              if (byte == '\n' || fillIndex >= BUFFER_SIZE - 1) {
                  break;
              }
          }
          else if (uart_status == HAL_TIMEOUT) {
              // Check screen timeout again during UART wait
              if (HAL_GetTick() - last_input_time >= screen_clear_timeout) {
                  Paint_Clear(BLACK);
                  OLED_0in96_display(BlackImage);
                  x_pos = 10;
                  y_pos = 0;
                  last_input_time = HAL_GetTick();
              }
          }
      } while (uart_status == HAL_OK);

      // 3. Process received data if any
      if (fillIndex > 0) {
          // Null termination handling
          if (buffer0[fillIndex - 1] == '\n') {
              buffer0[fillIndex - 1] = '\0';
          }
          buffer0[fillIndex] = '\0';

          // Trim trailing spaces
          char *buffer_str = (char*)buffer0;
          char *end = buffer_str + strlen(buffer_str) - 1;
          while (end >= buffer_str && *end == ' ') *end-- = '\0';

          // Word processing
          if (strlen(buffer_str) > 0) {
              char *current_word = buffer_str;
              while (*current_word != '\0') {
          		  // Skip leading spaces
          		  while (*current_word == ' ') {
          			  current_word++;
          		  }
          		  if (*current_word == '\0') {
          			  break;
          		  }

          		  // Find end of current word
          		  char *word_end = strchr(current_word, ' ');
          		  if (word_end == NULL) {
          			  word_end = current_word + strlen(current_word);
          		  }

          		  // Temporarily null-terminate the word
          		  char temp = *word_end;
          		  *word_end = '\0';

          		  // Calculate word width
          		  uint16_t word_width = strlen(current_word) * Font12.Width;
          		  int space_needed = (x_pos != 10) ? 1 : 0; // Check if not at line start
          		  uint16_t space_width = space_needed * Font12.Width;
          		  uint16_t total_width = space_width + word_width;

          		  // Check horizontal fit
          		  if (x_pos + total_width > OLED_0in96_HEIGHT) {
          			  x_pos = 10;
          			  y_pos += Font12.Height;

          			  // Check vertical overflow
          			  if (y_pos + Font12.Height > OLED_0in96_WIDTH) {
          				  Paint_Clear(BLACK);
          				  y_pos = 0;
          				  x_pos = 10;
          			  }

          			  space_needed = 0; // Reset space after new line
          		  }

          		  // Draw space if needed
          		  if (space_needed) {
          			  Paint_DrawString_EN(x_pos, y_pos, " ", &Font12, WHITE, BLACK);
          			  x_pos += Font12.Width;
          		  }

          		  // Draw the word (cast to char* for display function)
          		  Paint_DrawString_EN(x_pos, y_pos, current_word, &Font12, WHITE, BLACK);
          		  x_pos += word_width;

          		  // Restore buffer and move to next word
          		  *word_end = temp;
          		  current_word = word_end;

          		  // Skip consecutive spaces
          		  while (*current_word == ' ') {
          			  current_word++;
          			  if (*current_word == '\0') break;
          		  }
                  OLED_0in96_display(BlackImage);
                  last_input_time = HAL_GetTick(); // Reset timer after drawing
              }
          }

          // Reset buffer
          memset(buffer0, 0, sizeof(buffer0));
      }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI48;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2S1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S1_Init(void)
{

  /* USER CODE BEGIN I2S1_Init 0 */

  /* USER CODE END I2S1_Init 0 */

  /* USER CODE BEGIN I2S1_Init 1 */

  /* USER CODE END I2S1_Init 1 */
  hi2s1.Instance = SPI1;
  hi2s1.Init.Mode = I2S_MODE_MASTER_RX;
  hi2s1.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s1.Init.DataFormat = I2S_DATAFORMAT_24B;
  hi2s1.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s1.Init.AudioFreq = I2S_AUDIOFREQ_16K;
  hi2s1.Init.CPOL = I2S_CPOL_LOW;
  if (HAL_I2S_Init(&hi2s1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S1_Init 2 */

  /* USER CODE END I2S1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3|OLED_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OLED_DC_Pin|OLED_RST_Pin|IIC_SCL_SOFT_Pin|IIC_SDA_SOFT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 OLED_CS_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_3|OLED_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : OLED_DC_Pin OLED_RST_Pin IIC_SCL_SOFT_Pin IIC_SDA_SOFT_Pin */
  GPIO_InitStruct.Pin = OLED_DC_Pin|OLED_RST_Pin|IIC_SCL_SOFT_Pin|IIC_SDA_SOFT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
