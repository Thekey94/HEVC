/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern __IO uint32_t uwTick;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define INDICATOR_PWM_CHANNEL		TIM_CHANNEL_2
#define PILOT_PWM_CHANNEL			TIM_CHANNEL_1
#define Set_Indicator_Duty_Value(x)				Set_PWM_Duty_Value(x , INDICATOR_PWM_CHANNEL)
#define Set_Pilot_Duty_Value(x)					Set_PWM_Duty_Value(x , PILOT_PWM_CHANNEL)
/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void Set_PWM_Duty_Value(uint32_t duty_percent ,uint32_t Channel);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RELAY_1_Pin GPIO_PIN_4
#define RELAY_1_GPIO_Port GPIOA
#define RELAY_2_Pin GPIO_PIN_5
#define RELAY_2_GPIO_Port GPIOA
#define EM_LOCK_Pin GPIO_PIN_1
#define EM_LOCK_GPIO_Port GPIOB
#define EM_LOCKB2_Pin GPIO_PIN_2
#define EM_LOCKB2_GPIO_Port GPIOB
#define WIFI_BOOT_Pin GPIO_PIN_14
#define WIFI_BOOT_GPIO_Port GPIOB
#define WIFI_RST_Pin GPIO_PIN_15
#define WIFI_RST_GPIO_Port GPIOB
#define LED_DIN_Pin GPIO_PIN_12
#define LED_DIN_GPIO_Port GPIOA
#define AC_Integrity_INT_Pin GPIO_PIN_15
#define AC_Integrity_INT_GPIO_Port GPIOA
#define EM_LOCKB3_Pin GPIO_PIN_3
#define EM_LOCKB3_GPIO_Port GPIOB
#define DC_Integ_Pin GPIO_PIN_4
#define DC_Integ_GPIO_Port GPIOB
#define AC_INTEG_Pin GPIO_PIN_5
#define AC_INTEG_GPIO_Port GPIOB
#define AC_INTEGB6_Pin GPIO_PIN_6
#define AC_INTEGB6_GPIO_Port GPIOB
#define AC_INTEGB7_Pin GPIO_PIN_7
#define AC_INTEGB7_GPIO_Port GPIOB
#define AC_INTEGB8_Pin GPIO_PIN_8
#define AC_INTEGB8_GPIO_Port GPIOB
#define AC_INTEGB9_Pin GPIO_PIN_9
#define AC_INTEGB9_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define TIM1_RELOAD_VALUE			719

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
