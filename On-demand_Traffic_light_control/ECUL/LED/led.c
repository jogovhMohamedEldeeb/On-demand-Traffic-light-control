/*
 * led.c
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */

#include "led.h"

Std_ReturnType Led_Init(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = OUTPUT
		};
		ret = DIO_pin_dirction_init(&led_1);
		ret = DIO_write_logic(&led_1, DIO_LOW);
	}
	return ret;
}

Std_ReturnType Led_Turn_On(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = OUTPUT
		};
		ret = DIO_write_logic(&led_1, DIO_HIGH);
	}
	return ret;
}

Std_ReturnType Led_Turn_Off(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = OUTPUT
		};
		ret = DIO_write_logic(&led_1, DIO_LOW);
	}
	return ret;
}
Std_ReturnType Led_Toggle(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ST_pinCofig_t led_1 =
		{
			.port = led->port,
			.pin = led->pin,
			.pin_logic = led->status,
			.pin_direction = OUTPUT
		};
		ret = DIO_pin_toggle(&led_1);
	}
	return ret;
}
EN_ledStatus_t Led_State(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		return led->status;
	}
}
Std_ReturnType Led_Blink_aSecond(const ST_led_t* led)
{
	Std_ReturnType ret = E_OK;
	if(led == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		/* normal mode */
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);

		/* select prescaler 8 */
		TCCR2 = TCCR2 | 0X02;

		TCNT2 = 56;

		for(uint16 i=0 ; i<25000 ; i++)
		{
			while(TCNT2);/* still loop to overflow */
			TCNT2 = 56;
			if(i%2500 == 0)
			{
				Led_Toggle(led);
			}
		}
	}
	return ret;
}
Std_ReturnType Two_Led_Blink_aSecond(const ST_led_t* led_1, const ST_led_t* led_2)
{
	Std_ReturnType ret = E_OK;
	if(led_1 == NULL || led_2 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		CLR_BIT(TCCR2,WGM20);
		CLR_BIT(TCCR2,WGM21);

		TCCR2 = TCCR2 | 0X02;

		TCNT2 = 56;

		for(uint16 i=0 ; i<25000 ; i++)
		{
			while(TCNT2);
			TCNT2 = 56;
			if(i%2500 == 0)
			{
				Led_Toggle(led_1);
				Led_Toggle(led_2);
			}
		}
	}
	return ret;
}
