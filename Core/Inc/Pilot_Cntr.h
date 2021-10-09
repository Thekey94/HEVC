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

/*Data types Defines ---------------------------------------------------------*/
typedef enum PCTR_Return_Type
{
	PCTR_OK,
	PCTR_NOT_OK
}PCTR_Return_Type;

typedef enum PCTR_Init_Status
{
	PCTR_NOT_INITIALIZED,
	PCTR_INITIALIZED
}PCTR_Init_Status;

typedef enum PCTR_EV_State
{
	EV_NOT_CONNECTED,
	EV_CONNECTED,
	EV_CHARGING,
	EV_CHARGING_VENT_REQ,
	EV_ERROR,
	EV_UNKNOWN
}PCTR_EV_State;

void PCTR_init(void);
void PCTR_SET_EV_STATE ( PCTR_EV_State state);
void PCTR_PWM_Handller(void);


PCTR_Return_Type PCTR_Set_Duty_Cycle (uint8_t value);

#endif /* INC_PILOT_CNTR_H_ */
