/*
 * app.h
 *
 *  Created on: 11 Dec 2023
 *      Author: mohamed_eldeeb
 */

#include "app.h"


ST_led_t pedestriansGrean =
{
	.port = PORTB_INDEX,
	.pin = PIN0,
	.status = LED_OFF
};

ST_led_t pedestriansYellow =
{
	.port = PORTB_INDEX,
	.pin = PIN1,
	.status = LED_OFF
};

ST_led_t pedestriansRed =
{
	.port = PORTB_INDEX,
	.pin =  PIN2,
	.status = LED_OFF
};


ST_led_t carGrean =
{
	.port = PORTA_INDEX,
	.pin = PIN0,
	.status = LED_OFF
};

ST_led_t carYellow =
{
	.port = PORTA_INDEX,
	.pin = PIN1,
	.status = LED_OFF
};

ST_led_t carRed =
{
	.port = PORTA_INDEX,
	.pin = PIN2,
	.status = LED_OFF
};

ST_externalInterrupt_t ext_interrupt_0 =
{
	.source = EXI_INT0,
	.edge = EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE,
	.INT0_fpt = ifPressed
} ;

 Std_ReturnType ret = E_OK;
 volatile uint8_t carState;
void appStart()
{


	ret = EXI_interrupt_init(&ext_interrupt_0);
	ret = EXI_CallBack(&ext_interrupt_0);

	ret = Led_Init(&pedestriansGrean);
	ret = Led_Init(&pedestriansYellow);
	ret = Led_Init(&pedestriansRed);

	ret = Led_Init(&carGrean);
	ret = Led_Init(&carYellow);
	ret = Led_Init(&carRed);

    while (1)
    {
		normalMode();
    }
}

void ifPressed()
{
	pedstrainsMode();
}
/*

	Cars' LEDs will be changed every 5 sec starting from Green then yellow then red then yellow then Green.
	The Yellow LED will blink for 5 seconds before moving to Green or Red LEDs.

*/
void normalMode()
{
	void turnOffLeds();

	carState = greanCarState;
	ret = Led_Turn_On(&carGrean);
	ret = Led_Turn_On(&pedestriansRed);
	delay5s();

	carState = yellowCarState;
	ret = Two_Led_Blink_aSecond(&carYellow, &pedestriansYellow);

	turnOffLeds();
	carState = redCarState;
	ret = Led_Turn_On(&carRed);
	ret = Led_Turn_On(&pedestriansGrean);
	delay5s();

	carState = yellowCarState;
	ret = Two_Led_Blink_aSecond(&carYellow, &pedestriansYellow);

	turnOffLeds();
	carState = greanCarState;
	ret = Led_Turn_On(&carGrean);
	ret = Led_Turn_On(&pedestriansRed);
	delay5s();
}

/*	Change from normal mode to pedestrian mode
		when the pedestrian button is pressed.*/
void pedstrainsMode()
{
	//If pressed when the cars' Red LED is on
	if(carState == redCarState)
	{
		carRedLedOn();
	}

	/*If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking */
	else if( (carState == greanCarState) || (carState == yellowCarState) )
	{
		carGreenLedOn();
	}
	turnOffLeds();

	/*At the end of the two states the cars' Red LED will be off */
	ret = Led_Turn_Off(&carRed);

	/*   both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.*/
	ret = Led_Turn_On(&pedestriansGrean);
	ret = Two_Led_Blink_aSecond(&pedestriansYellow,&carYellow);

	/*After the 5 seconds the pedestrian Green LED will be off */
	ret = Led_Turn_Off(&pedestriansGrean);

	/* both the pedestrian Red LED and the cars' Green LED will be on. */
	ret = Led_Turn_On(&pedestriansRed);
	ret = Led_Turn_On(&carRed);

	delay5s();

	/* Traffic lights signals are going to the normal mode again. */
	normalMode();
}

void turnOffLeds()
{
	ret = Led_Turn_Off(&carRed);
	ret = Led_Turn_Off(&carGrean);
	ret = Led_Turn_Off(&carYellow);

	ret = Led_Turn_Off(&pedestriansRed);
	ret = Led_Turn_Off(&pedestriansGrean);
	ret = Led_Turn_Off(&pedestriansYellow);
}
void carGreenLedOn()
{
	ret = Led_Turn_Off(&pedestriansYellow);
	ret = Led_Turn_Off(&carYellow);

	//the pedestrian Red LED will be on
	ret = Led_Turn_On(&pedestriansRed);

	//then both Yellow LEDs start to blink for five seconds
	ret = Two_Led_Blink_aSecond(&carYellow, &pedestriansYellow);

	//then the cars' Red LED and pedestrian Green LEDs are on for five seconds
	ret = Led_Turn_Off(&carGrean);
	ret = Led_Turn_Off(&pedestriansRed);

	ret = Led_Turn_On(&carRed);
	ret = Led_Turn_On(&pedestriansGrean);
	delay5s();
}
void carRedLedOn()
{
	turnOffLeds();

	//the pedestrian's Green LED
	ret = Led_Turn_On(&pedestriansGrean);

	//and the cars' Red LEDs will be on for five seconds
	ret = Led_Turn_On(&carRed);

	delay5s();
}
