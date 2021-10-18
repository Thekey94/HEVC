/*
 * Pilot_Cntr.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Ashraf
 */
#include <Pilot_Cntr.h>


static uint8_t PCTR_Duty_Cycle;
static uint8_t PCTR_PWM_Counter;
static PCTR_Init_Status is_PCTR_initialized = PCTR_NOT_INITIALIZED;
PCTR_EV_State EV_State;

void PCTR_init(void)
{
	HAL_GPIO_WritePin(PWM_PIN_BANK, PWM_PIN, GPIO_PIN_SET);
	EV_State = EV_NOT_CONNECTED;
	PCTR_PWM_Counter = 0;
	PCTR_Duty_Cycle = 100;

	is_PCTR_initialized = PCTR_INITIALIZED;
}

void PCTR_SET_EV_STATE ( PCTR_EV_State state)
{
	EV_State = state;
}

PCTR_Return_Type PCTR_Set_Duty_Cycle (uint8_t value)
{
	PCTR_Return_Type ret_val;
	if (value >= 0 && value <= 100)
	{
		PCTR_Duty_Cycle = value;
		ret_val = PCTR_OK;
	}
	else
	{
		ret_val = PCTR_NOT_OK;
	}

	return(ret_val);
}


void PCTR_PWM_Handller(void)
{
	if ( (is_PCTR_initialized == PCTR_INITIALIZED) && ( (EV_State == EV_CONNECTED) || (EV_State == EV_CHARGING) ||(EV_State == EV_CHARGING_VENT_REQ)  ))
	{
		if (PCTR_PWM_Counter <= 100)
		{
			if (PCTR_PWM_Counter <= PCTR_Duty_Cycle)
			{
				HAL_GPIO_WritePin(PWM_PIN_BANK, PWM_PIN, GPIO_PIN_SET);
				PCTR_PWM_Counter++;
			}
			else
			{
				HAL_GPIO_WritePin(PWM_PIN_BANK, PWM_PIN, GPIO_PIN_RESET);
				PCTR_PWM_Counter++;
			}
		}
		else
		{
			PCTR_PWM_Counter = 0;
		}
	}
	else
	{
		//Do nothing
	}
}
