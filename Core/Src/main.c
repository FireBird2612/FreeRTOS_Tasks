/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "16x2_LCD.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define DWT_CTRL 					(*(volatile unsigned int *)0xE0001000)

#define SW1_PRESSED					0UL
#define SW2_PRESSED					1UL
#define BOTH_SW_PRESSED				2UL
#define NO_SW_PRESSED				3UL
#define NO_SW_PRESSED_RED_HIGH		4UL
#define NO_SW_PRESSED_GREEN_HIGH	5UL

#define CONTROL_NO_SW_PRESS_TIME	1000UL

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

/* USER CODE BEGIN PV */

TaskHandle_t sw_press_handle;
TaskHandle_t led_control_handle;
TaskHandle_t lcd_update_handle;


uint8_t switch_status[4];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

static void sw_press(void *param);
static void led_control(void *param);
static void lcd_update(void *param);

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
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */

  LCD_init();
  LCD_send_string("EMotoRad Assign");
  LCD_send_command(ROW_2);
  LCD_send_string("Sanket Gunjal");

  HAL_Delay(1000);
  /*	Contains status of the newly created task	*/
  BaseType_t stat;

  DWT_CTRL |= (1 << 0);					// Used by segger system view to enable the cyclic count

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  /*	Create a task for the Switch Press	*/
  stat = xTaskCreate(sw_press, "Switch Press", 128, NULL, 4, &sw_press_handle);
  configASSERT(stat == pdPASS);

  stat = xTaskCreate(led_control, "LED Control", 128, NULL, 2, &led_control_handle);
  configASSERT(stat == pdPASS);

  stat = xTaskCreate(lcd_update, "LCD Update", 128, NULL, 3, &lcd_update_handle);
  configASSERT(stat == pdPASS);

  /*	Start the scheduler	*/
  vTaskStartScheduler();


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
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

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GREEN_LED_Pin|RED_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : SW2_Pin SW1_Pin */
  GPIO_InitStruct.Pin = SW2_Pin|SW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : GREEN_LED_Pin RED_LED_Pin */
  GPIO_InitStruct.Pin = GREEN_LED_Pin|RED_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
static void sw_press(void *param){

	/*	prev_press are for debouncing	*/
	uint8_t sw1_prev_press, sw2_prev_press;
	uint8_t sw1_curr_press, sw2_curr_press;

	/*	pull-up on switch	*/
	sw1_prev_press = 1;
	sw2_prev_press = 1;

	while(1){

		sw1_curr_press = HAL_GPIO_ReadPin(SW1_GPIO_Port, SW1_Pin);			// If pressed, state = 0!
		sw2_curr_press = HAL_GPIO_ReadPin(SW2_GPIO_Port, SW2_Pin);

		/*	Check if both switch pressed, sw1 pressed only, sw2 pressed only, no switch pressed1	*/
		if((sw1_curr_press == GPIO_PIN_RESET && sw1_prev_press == GPIO_PIN_SET) && (sw2_curr_press == GPIO_PIN_RESET && sw2_prev_press == GPIO_PIN_SET)){
			xTaskNotify(led_control_handle, BOTH_SW_PRESSED, eSetValueWithOverwrite);
		}
		else if((sw1_curr_press == GPIO_PIN_RESET && sw1_prev_press == GPIO_PIN_SET) && (sw2_curr_press == GPIO_PIN_SET && sw2_prev_press == GPIO_PIN_SET)){
			xTaskNotify(led_control_handle, SW1_PRESSED, eSetValueWithOverwrite);
		}
		else if((sw1_curr_press == GPIO_PIN_SET && sw1_prev_press == GPIO_PIN_SET) && (sw2_curr_press == GPIO_PIN_RESET && sw2_prev_press == GPIO_PIN_SET)){
			xTaskNotify(led_control_handle, SW2_PRESSED, eSetValueWithOverwrite);
		}
		//else{
		//	xTaskNotify(led_control_handle, NO_SW_PRESSED, eSetValueWithOverwrite);
		//}
		sw1_prev_press = sw1_curr_press;
		sw2_prev_press = sw2_curr_press;

		vTaskDelay(pdMS_TO_TICKS(100));
	}

}

static void led_control(void *param){
	uint32_t notify_val;
	BaseType_t stat;
	uint8_t flag = 1;

	while(1){
		stat = xTaskNotifyWait(0, 0, &notify_val, pdMS_TO_TICKS(CONTROL_NO_SW_PRESS_TIME));
		if(stat == pdTRUE){
			// Event Occured!
			stat = 0;
			/*	If both Switch are not pressed at the same time, reset the state of LEDs	*/
			if(notify_val != BOTH_SW_PRESSED){
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
			}
			else{
				// Both switch are pressed at the same time!
				xTaskNotify(lcd_update_handle, BOTH_SW_PRESSED, eSetValueWithOverwrite);
			}

			switch(notify_val){
				case SW1_PRESSED:{
					// Send the notification to the LCD Update function
					xTaskNotify(lcd_update_handle, SW1_PRESSED, eSetValueWithOverwrite);
					HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
					break;
				}

				case SW2_PRESSED:{
					// Send the notification to the LCD Update function
					xTaskNotify(lcd_update_handle, SW2_PRESSED, eSetValueWithOverwrite);
					HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
					break;
				}

				default:{
					break;
				}
			}
		}
		else{
			if(flag){
				xTaskNotify(lcd_update_handle, NO_SW_PRESSED_RED_HIGH, eSetValueWithOverwrite);
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
				flag = 0;
			}
			else{
				xTaskNotify(lcd_update_handle, NO_SW_PRESSED_GREEN_HIGH, eSetValueWithOverwrite);
				HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				flag = 1;
			}
		}
	}
}

static void lcd_update(void *param){

	uint32_t notify_val;
	BaseType_t stat;

	while(1){
		/*	Wait Indefinitely for a notification*/
		stat = xTaskNotifyWait(0, 0, &notify_val, portMAX_DELAY);
		if(stat == pdTRUE){
			stat = 0;
			switch(notify_val){
				case NO_SW_PRESSED_RED_HIGH:{
					LCD_send_command(CLEAR_SCREEN);
					HAL_Delay(2);
					LCD_send_command(ROW_1);
					LCD_send_string("Act: No SW");
					LCD_send_command(ROW_2);
					LCD_send_string("Stat: Red HIGH");
					break;
				}

				case NO_SW_PRESSED_GREEN_HIGH: {
					LCD_send_command(CLEAR_SCREEN);
					HAL_Delay(2);
					LCD_send_command(ROW_1);
					LCD_send_string("Act: No SW");
					LCD_send_command(ROW_2);
					LCD_send_string("Stat: Green HIGH");
					break;
				}
				case SW1_PRESSED:{
					LCD_send_command(CLEAR_SCREEN);
					HAL_Delay(2);
					LCD_send_command(ROW_1);
					LCD_send_string("Act: SW1 HIGH");
					LCD_send_command(ROW_2);
					LCD_send_string("Stat: RED HIGH");
					break;
				}

				case SW2_PRESSED:{
					LCD_send_command(CLEAR_SCREEN);
					HAL_Delay(2);
					LCD_send_command(ROW_1);
					LCD_send_string("Act: SW2 HIGH");
					LCD_send_command(ROW_2);
					LCD_send_string("Stat: GREEN HIGH");
					break;
				}

				case BOTH_SW_PRESSED:{
					LCD_send_command(CLEAR_SCREEN);
					HAL_Delay(2);
					LCD_send_command(ROW_1);
					LCD_send_string("Act: SW1 & SW2");
					LCD_send_command(ROW_2);
					LCD_send_string("Stat: No Change");
					break;
				}
			}
		}
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
