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
#include "std_types.h"

/* Private Defines -----------------------------------------------------------*/
#define PWM_PIN							GPIO_PIN_5
#define PWM_PIN_BANK					GPIOB

#define ADC_MAX_VALUE					4095
#define VCC_IN							5000
#define EV_NOT_CONNECTED_VOLTAGE		(VCC_IN)
#define EV_CONNECTED_VOLTAGE			((VCC_IN/4) * 3)
#define EV_CHARGING_VOLTAGE				((VCC_IN/4) * 2)
#define EV_CHARGING_VENT_REQ_VOLTAGE	((VCC_IN/4) * 1)
#define EV_ERROR_VOLTAGE				((VCC_IN/4) * 0)
#define EV_UNKNOWN_VOLTAGE				6


#define MIN_NOT_CONNECTED_VOLTAGE 		(EV_NOT_CONNECTED_VOLTAGE+EV_CONNECTED_VOLTAGE)/2
#define MIN_CONNECTED_VOLTAGE			(EV_CONNECTED_VOLTAGE+EV_CHARGING_VOLTAGE)/2
#define MIN_CHARGING_VOLTAGE			(EV_CHARGING_VOLTAGE+EV_CHARGING_VENT_REQ_VOLTAGE)/2
#define MIN_VENT_REQ_VOLTAGE			(EV_CHARGING_VENT_REQ_VOLTAGE+EV_ERROR_VOLTAGE)/2

extern uint16_t adc_data[1];

/*Data types Defines ---------------------------------------------------------*/

typedef enum EVCH_Init_Status
{
	EVCH_NOT_INITIALIZED,
	EVCH_INITIALIZED
}EVCH_Init_Status;

typedef enum EVCH_EV_State
{
	EV_NOT_CONNECTED,
	EV_CONNECTED,
	EV_CHARGING,
	EV_CHARGING_VENT_REQ,
	EV_ERROR,
	EV_UNKNOWN
}EVCH_EV_State;

void EVCH_init(void);
std_ret EVCH_MainFunction (void);
void EVCH_SET_EV_STATE ( EVCH_EV_State state);
void PCTR_PWM_Handller(void);
void EVCH_Update_EV_State(uint16_t* AdcData);



#endif /* INC_PILOT_CNTR_H_ */
