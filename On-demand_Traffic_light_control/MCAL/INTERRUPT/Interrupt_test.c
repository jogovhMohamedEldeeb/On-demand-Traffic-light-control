
#include "Interrupt_interface.h"
#include "../../ECUL/LED/led.h"



void EXT0_Handeler();

ST_led_t led_0 =
{
	.port = PORTD_INDEX,
	.pin =  PIN0,
	.status = LED_OFF
};

void EXT0_Handeler()
{
	Led_Toggle(&led_0);
}

ST_externalInterrupt_t ext =
{
	.edge = EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE,
	.source = EXI_INT0,
	.INT0_fpt = EXT0_Handeler
};


void EXIT_Test()
{

	EXI_interrupt_init(&ext);
	EXI_CallBack(&ext);

	Led_Init(&led_0);

	while(1);
}

