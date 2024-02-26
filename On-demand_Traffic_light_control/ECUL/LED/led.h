/*
 * led.h
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef ECUL_LED_LED_H_
#define ECUL_LED_LED_H_
#include "../../MCAL/DIO/Dio_interface.h"
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "../../MCAL/TIMER/Timer_interface.h"
typedef enum
{
    LED_OFF = 0,
    LED_ON
}EN_ledStatus_t;


typedef struct
{
	uint8_t port;
	uint8_t pin;
    EN_ledStatus_t status;
}ST_led_t;

/* function test*/
void ledTest();

Std_ReturnType Led_Init(const ST_led_t* led);
Std_ReturnType Led_Turn_On(const ST_led_t* led);
Std_ReturnType Led_Turn_Off(const ST_led_t* led);
Std_ReturnType Led_Toggle(const ST_led_t* led);
EN_ledStatus_t Led_State(const ST_led_t* led);
Std_ReturnType Led_Blink_aSecond(const ST_led_t* led);
Std_ReturnType Two_Led_Blink_aSecond(const ST_led_t* led_1, const ST_led_t* led_2);

#endif /* ECUL_LED_LED_H_ */
