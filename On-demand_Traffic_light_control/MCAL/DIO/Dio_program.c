/*
 * Dio_program.c
 *
 *  Created on: 11 Dec 2023
 *      Author: mohamed_eldeeb
 */

#include "Dio_interface.h"

 

volatile uint8_t *ddr_regster[]  = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8_t *port_regster[] = {&PORTA,&PORTB,&PORTC,&PORTD};
volatile uint8_t *pin_regster[]  = {&PINA,&PINB,&PINC,&PIND};





/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_pin_dirction_init(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(pinObject->pin_direction)
		{
			case OUTPUT :
			SET_BIT(*(ddr_regster[pinObject->port]), pinObject->pin);
			break;

			case INPUT :
			CLR_BIT(*(ddr_regster[pinObject->port]), pinObject->pin);
			break;

			default:
			ret = E_NOT_OK;
		}
	}
	return ret;
}


/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @param dirction Pointer to the PIN DIRECTION configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_get_pin_direction(const ST_pinCofig_t* pinObject, EN_pinDirection_t* dirction)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*dirction = READ_BIT(*pin_regster[pinObject->port], pinObject->pin);
	}
	return ret;
}


/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @param logic Object from the logic configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_write_logic(const ST_pinCofig_t* pinObject, EN_logic_t logic)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(logic)
		{
			case DIO_HIGH :
				SET_BIT(*(port_regster[pinObject->port]), pinObject->pin);
				break;

			case DIO_LOW :
				CLR_BIT(*(port_regster[pinObject->port]), pinObject->pin);
				break;

			default :
				ret = E_NOT_OK;
		}
	}
	return ret;
}



/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @param logic Pointer to the logic configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_read_logic(const ST_pinCofig_t* pinObject, EN_logic_t* logic)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*logic = READ_BIT(*pin_regster[pinObject->port], pinObject->pin);
	}
	return ret;
}


/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_pin_toggle(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		TOGGLE_BIT(*port_regster[pinObject->port], pinObject->pin);
	}
	return ret;
}


/**
 *
 * @param pinObject Pointer to the PIN configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType DIO_pin_init(const ST_pinCofig_t* pinObject)
{
	Std_ReturnType ret = E_OK;
	if(pinObject == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = DIO_pin_dirction_init(pinObject);
		ret = DIO_write_logic(pinObject, pinObject->pin_logic);
	}
	return ret;
}
