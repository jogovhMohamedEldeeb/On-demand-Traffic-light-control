/*
 * app.c
 *
 *  Created on: 11 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef APP_H_
#define APP_H_


#include "../MCAL/DIO/Dio_interface.h"
#include "../MCAL/INTERRUPT/Interrupt_interface.h"
#include "../MCAL/TIMER/Timer_interface.h"
#include "../ECUL/BUTTON/button.h"
#include "../ECUL/LED/led.h"
#include <avr/delay.h>

#define redCarState						0
#define yellowCarState					1
#define greanCarState					2



void appStart();
void ifPressed();
void normalMode();
void pedstrainsMode();
void turnOffLeds();
void carGreenLedOn();
void carRedLedOn();

#endif /* APP_H_ */
