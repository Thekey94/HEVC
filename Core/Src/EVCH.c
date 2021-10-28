/*
 * EVCH.c
 * Electric Vehicle Communication Handler
 *  Created on: Oct 3, 2021
 *      Author: Ahmed Ashraf
 */
#include <EVCH.h>
#include <main.h>
#include <INDH.h>

static EVCH_Init_Status is_EVCH_initialized = EVCH_NOT_INITIALIZED;
EVCH_EV_State EV_State;
uint16_t voltage;
void EVCH_init(void)
{
	Set_Pilot_Duty_Value(100);
	EV_State = EV_NOT_CONNECTED;

	is_EVCH_initialized = EVCH_INITIALIZED;

}

std_ret EVCH_MainFunction (void)
{
	EVCH_Update_EV_State(adc_data);
	return R_OK;
}

void EVCH_Update_EV_State(uint16_t* AdcData)
{

	voltage = (AdcData[0] * VCC_IN) / ADC_MAX_VALUE;

	if	(voltage >= MIN_NOT_CONNECTED_VOLTAGE )
	{
		EV_State = EV_NOT_CONNECTED;
		INDH_Set_Indication_type(IND_OFF);
	}
	else if(voltage >= MIN_CONNECTED_VOLTAGE )
	{
		EV_State = EV_CONNECTED;
		INDH_Set_Indication_type(IND_ON);
	}
	else if(voltage >= MIN_CHARGING_VOLTAGE )
	{
		EV_State = EV_CHARGING;
		INDH_Set_Indication_type(IND_FADE);
	}
	else if(voltage >= MIN_VENT_REQ_VOLTAGE )
	{
		EV_State = EV_CHARGING_VENT_REQ;
		INDH_Set_Indication_type(IND_FLASH);
	}
	else
	{
		EV_State = EV_ERROR;
		//to do error handl
	}

}

void EVCH_SET_EV_STATE ( EVCH_EV_State state)
{
	EV_State = state;

}


