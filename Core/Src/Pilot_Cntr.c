/*
 * Pilot_Cntr.c
 *
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Ashraf
 */
#include <Pilot_Cntr.h>
volatile uint8_t usless_counter =0;

void PWM_Handller(void)
{
	usless_counter ++;
	if (usless_counter >= 1000)
	{
		HAL_GPIO_TogglePin(PWM_PIN_BANK, PWM_PIN);
		usless_counter = 0;
	}
}
