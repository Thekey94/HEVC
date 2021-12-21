/*
 * INDH.c
 *
 *  Created on: Oct 27, 2021
 *      Author: Ahmed Ashraf
 */

#include <INDH.h>
#include <std_types.h>
#include <main.h>

static Indication_type Current_Indication = IND_OFF;
static uint8_t local_ind_counter;
static uint8_t local_ind_step;

/*
 * INDH_MainFunction Indication Handler main function
 * this function should be called every 100 ms and update the indication cyclic accordingly
 * */
std_ret INDH_MainFunction(void)
{
	std_ret ret_val;

	switch (Current_Indication)
	{
	case IND_OFF :
		Set_Indicator_Duty_Value(0);
		break;

	case IND_ON :
		Set_Indicator_Duty_Value(100);
		break;

	case IND_FLASH :

		if (local_ind_counter == 100)
		{
			local_ind_step = -(FLASH_STEP) ;
		}

		if (local_ind_counter == 0)
		{
			local_ind_step = FLASH_STEP ;
		}

		if (local_ind_counter >= 50)
		{
			Set_Indicator_Duty_Value(100);
		}

		else if (local_ind_counter < 50)
		{
			Set_Indicator_Duty_Value(0);
		}

		local_ind_counter += local_ind_step;
		break;

	case IND_FADE :

		if (local_ind_counter == 100)
		{
			local_ind_step = -(FADE_STEP);
		}

		if (local_ind_counter == 0)
		{
			local_ind_step = FADE_STEP;
		}

		local_ind_counter += local_ind_step;
		Set_Indicator_Duty_Value(local_ind_counter);
		break;

	case IND_HEART_BEAT :
		//to do implement hear beat sequence
		local_ind_counter += local_ind_step;

		switch(local_ind_counter)

		{
		case 0:
			Set_Indicator_Duty_Value(25);
			break;
		case 10:
			Set_Indicator_Duty_Value(50);
			break;

		case 20:
			Set_Indicator_Duty_Value(100);
			break;

		case 40:
			Set_Indicator_Duty_Value(50);
			break;
		case 50:
			Set_Indicator_Duty_Value(0);
			break;

		case 60:
			Set_Indicator_Duty_Value(50);
			break;

		case 70:
			Set_Indicator_Duty_Value(100);
			break;

		case 80:
			Set_Indicator_Duty_Value(75);
			break;

		case 90:
			Set_Indicator_Duty_Value(50);
			break;

		case 100:
			Set_Indicator_Duty_Value(25);
			break;

		case 110:
			Set_Indicator_Duty_Value(0);
			break;

		case 180:
			local_ind_counter = 0;
			break;

		default:
			//do nothing
			break;

		}

		break;

	default :
		Set_Indicator_Duty_Value(0);
		break;
	}


	ret_val = R_OK;
	return ret_val;
}

/*
 * INDH_Set_Indication_type this function should change the type of indication
 * */
std_ret INDH_Set_Indication_type(Indication_type indication)
{
	std_ret ret_val;
	if (indication == IND_OFF || indication == IND_FLASH || indication == IND_ON ||
			indication == IND_FADE || indication == IND_HEART_BEAT )
	{
		/*set the new indication mode and reset the indication counters if its a new state*/
		if (Current_Indication != indication)
		{
			Current_Indication = indication;
			local_ind_step = 10;
			local_ind_counter = 0;
		}
		ret_val = R_OK;
	}
	else
	{
		ret_val = R_ERROR;
		//to do report internal error
	}
	return ret_val;
}
