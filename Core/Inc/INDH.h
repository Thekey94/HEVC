/*
 * INDH.h
 *
 *  Created on: Oct 27, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef INC_INDH_H_
#define INC_INDH_H_

#include <std_types.h>

#define FLASH_STEP			20
#define FADE_STEP			10

typedef enum
{
	IND_OFF,
	IND_ON,
	IND_FLASH,
	IND_FADE,
	IND_HEART_BEAT
}Indication_type;


std_ret INDH_MainFunction(void);
std_ret INDH_Set_Indication_type(Indication_type indication);

#endif /* INC_INDH_H_ */
