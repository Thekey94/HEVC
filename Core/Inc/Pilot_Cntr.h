/*
 * Pilot_Cnrt.h
 *
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef INC_PILOT_CNTR_H_
#define INC_PILOT_CNTR_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private Defines -----------------------------------------------------------*/
#define PWM_PIN			GPIO_PIN_10
#define PWM_PIN_BANK	GPIOA

void PWM_Handller(void);



#endif /* INC_PILOT_CNTR_H_ */
