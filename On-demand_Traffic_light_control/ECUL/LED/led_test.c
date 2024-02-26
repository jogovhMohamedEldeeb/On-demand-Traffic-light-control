
#include "led.h"

ST_led_t led1 =
{
	.port = PORTD_INDEX,
	.pin = PIN0,
	.status = LED_OFF
};

void ledTest()
{
	Led_Init(&led1);
	while(1)
	{
		//Led_Turn_Off(&led1);
		//Led_Turn_On(&led1);
		Led_Toggle(&led1);
	}
}
