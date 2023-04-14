/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "adc.h"
#include "dma.h"
#include "fatfs.h"
#include "sdio.h"
#include "usart.h"
#include "gpio.h"

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

/* USER CODE BEGIN PV */
  FRESULT fres;
  uint16_t raw_temp;
  float temp_c;
  char log_path[] = "/TEST.TXT";
  char buf[20];                             /* File read buffer */
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
FRESULT AppendToFile(char* path, size_t path_len, char* msg, size_t msg_len);
void printError(FRESULT errornumber);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_SDIO_SD_Init();
  MX_FATFS_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  HAL_Delay(1000);
	  fres=AppendToFile(log_path, sizeof(log_path), "fran perea quien lo esedea", sizeof("fran perea quien lo esedea"));
	  printError(fres);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 6;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

// print error trough uart
void printError(FRESULT errornumber){
	  HAL_UART_Transmit(&huart3, "\n\r" ,sizeof("\n\r"), 100);
	  HAL_Delay(10);
	  switch (errornumber) {
		case FR_OK:
			HAL_UART_Transmit(&huart3,
					"FR_OK = 0,/* (0) Succeeded */",
					sizeof("FR_OK = 0,/* (0) Succeeded */"),
					100);
			break;
		case FR_DISK_ERR:
			HAL_UART_Transmit(&huart3,
					"FR_DISK_ERR,/* (1) A hard error occurred in the low level disk I/O layer */",
					sizeof("FR_DISK_ERR,/* (1) A hard error occurred in the low level disk I/O layer */"),
					100);
			break;
		case FR_INT_ERR:
			HAL_UART_Transmit(&huart3,
					"FR_INT_ERR,/* (2) Assertion failed */",
					sizeof("FR_INT_ERR,/* (2) Assertion failed */"),
					100);
			break;
		case FR_NOT_READY:
			HAL_UART_Transmit(&huart3,
					"FR_NOT_READY,/* (3) The physical drive cannot work */",
					sizeof("FR_NOT_READY,/* (3) The physical drive cannot work */"),
					100);
			break;
		case FR_NO_FILE:
			HAL_UART_Transmit(&huart3,
					"FR_NO_FILE,/* (4) Could not find the file */",
					sizeof("FR_NO_FILE,/* (4) Could not find the file */"),
					100);
			break;
		case FR_NO_PATH:
			HAL_UART_Transmit(&huart3,
					"FR_NO_PATH,/* (5) Could not find the path */",
					sizeof("FR_NO_PATH,/* (5) Could not find the path */"),
					100);
			break;
		case FR_INVALID_NAME:
			HAL_UART_Transmit(&huart3,
					"FR_INVALID_NAME,/* (6) The path name format is invalid */",
					sizeof("FR_INVALID_NAME,/* (6) The path name format is invalid */"),
					100);
			break;
		case FR_DENIED:
			HAL_UART_Transmit(&huart3,
					"FR_DENIED,/* (7) Access denied due to prohibited access or directory full */",
					sizeof("FR_DENIED,/* (7) Access denied due to prohibited access or directory full */"),
					100);
			break;
		default:
			HAL_UART_Transmit(&huart3,
					"something else",
					sizeof("something else"),
					100);
			break;
	}
}

// Append string to file given at path
FRESULT AppendToFile(char* path, size_t path_len, char* msg, size_t msg_len) {

  FATFS fs;
  FIL myFILE;
  UINT testByte;
  FRESULT stat;

  // Bounds check on strings
  if ( (path[path_len] != 0) || (msg[msg_len] != 0) ) {
    return FR_INVALID_NAME;
  }

  // Re-initialize SD
  if ( BSP_SD_Init() != MSD_OK ) {
    return FR_NOT_READY;
  }

  // Re-initialize FATFS
  if ( FATFS_UnLinkDriver(SDPath) != 0 ) {
    return FR_NOT_READY;
  }
  if ( FATFS_LinkDriver(&SD_Driver, SDPath) != 0 ) {
    return FR_NOT_READY;
  }

  // Mount filesystem
  stat = f_mount(&fs, SDPath, 1);
  if (stat != FR_OK) {
    f_mount(0, SDPath, 0);
    return stat;
  }

  // Open file for appending
  stat = f_open(&myFILE, path, FA_WRITE | FA_OPEN_APPEND);
  if (stat != FR_OK) {
    f_mount(0, SDPath, 0);
    return stat;
  }

  // Write message to end of file
  stat = f_write(&myFILE, msg, msg_len, &testByte);
  if (stat != FR_OK) {
    f_mount(0, SDPath, 0);
    return stat;
  }

  // Sync, close file, unmount
  stat = f_close(&myFILE);
  f_mount(0, SDPath, 0);
  return stat;
}
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
