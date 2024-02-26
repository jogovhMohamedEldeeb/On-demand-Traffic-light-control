/*
 * button.h
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef ECUL_BUTTON_BUTTON_H_
#define ECUL_BUTTON_BUTTON_H_
#include "../../MCAL/DIO/Dio_interface.h"

//BUTTON STATE
#define BUTTON_LOW  0
#define BUTTON_HIGH 1
typedef enum
{
	PULL_UP = 0,
	PULL_DOWN
}EN_connction_t;

typedef enum
{
	PRESSED = 0,
	RELEASSED
}EN_buttonState;

typedef struct
{
	ST_pinCofig_t pin;
	EN_connction_t connection;
	EN_buttonState state;
}ST_buton_t;

//initialize
Std_ReturnType  BUTTON_init(const ST_buton_t *button);
//button read
Std_ReturnType BUTTON_read(const ST_buton_t *button,EN_buttonState *btn_state);

#endif /* ECUL_BUTTON_BUTTON_H_ */
