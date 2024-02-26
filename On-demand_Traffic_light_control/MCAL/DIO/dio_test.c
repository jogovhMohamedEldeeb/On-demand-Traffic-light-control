

#include "Dio_interface.h"

ST_pinCofig_t pin1 =
{
	.pin =  PIN0,
	.port = PORTB_INDEX,
	.pin_logic = DIO_HIGH,
	.pin_direction = OUTPUT
};

void dioTest()
{
	DIO_pin_init(&pin1);
	DIO_pin_toggle(&pin1);
}
