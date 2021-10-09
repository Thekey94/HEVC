/*
 * Pilot_Cntr.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Ashraf
 */
#include <Pilot_Cntr.h>


static uint8_t PCTR_Duty_Cycle = 5;
static uint8_t PCTR_PWM_Counter;

PCTR_Return_Type PCTR_Set_Duty_Cycle (uint8_t value)
{
	PCTR_Return_Type ret_val;
	if (value >= 0 && value <= 100)
	{
		value = PCTR_Duty_Cycle;
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
	if (PCTR_PWM_Counter <= 10)
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
