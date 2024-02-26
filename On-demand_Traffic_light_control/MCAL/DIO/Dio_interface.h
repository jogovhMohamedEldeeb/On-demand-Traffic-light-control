/*
 * Dio_interface.h
 *
 *  Created on: 11 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "Dio_private.h"



typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH
}EN_logic_t;

typedef enum
{
	PORTA_INDEX = 0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX,
	PORTE_INDEX
}EN_portIndex_t;

typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}EN_pinNumber_t;

typedef enum
{
	OUTPUT = 0,
	INPUT
}EN_pinDirection_t;


typedef struct
{
	EN_portIndex_t port;
	EN_pinNumber_t pin;
	EN_pinDirection_t pin_direction;
	EN_logic_t pin_logic;
}ST_pinCofig_t;

/* function test */
void dioTest();

Std_ReturnType DIO_pin_dirction_init(const ST_pinCofig_t* pinObject);
Std_ReturnType DIO_get_pin_direction(const ST_pinCofig_t*pinObject, EN_pinDirection_t* dirction);
Std_ReturnType DIO_write_logic(const ST_pinCofig_t* pinObject, EN_logic_t logic);
Std_ReturnType DIO_read_logic(const ST_pinCofig_t* pinObject, EN_logic_t* logic);
Std_ReturnType DIO_pin_toggle(const ST_pinCofig_t* pinObject);
Std_ReturnType DIO_pin_init(const ST_pinCofig_t* pinObject);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
