/*
 * Interrupt_interface.h
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_
#include "../../UTILS/STD_TYPES.h"
#include "../../UTILS/BIT_MATH.h"
#include "Interrupt_private.h"


#define EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT1_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT1_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE			0x01
#define EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x00



#define EXI_INT0_SET_EDGE(EDGE)								(MCUCR  |= EDGE)
#define EXI_INT1_SET_EDGE(EDGE)								(MCUCR  |= (EDGE<<2))
#define EXI_INT2_SET_EDGE(EDGE)								(MCUCSR |= (EDGE<<6))


typedef enum
{
	EXI_INT0,
	EXI_INT1,
	EXI_INT2
}EN_externalInterruptSource_t;


typedef struct
{
	EN_externalInterruptSource_t source;
	uint8_t edge;
	void (*INT0_fpt) (void);
	void (*INT1_fpt) (void);
	void (*INT2_fpt) (void);

}ST_externalInterrupt_t;

/* funciton test */
void EXIT_Test();

Std_ReturnType EXI_interrupt_init(const ST_externalInterrupt_t* interrupt);
Std_ReturnType EXI_CallBack(const ST_externalInterrupt_t* interrupt);



#endif /* MCAL_INTERRUPT_INTERRUPT_INTERFACE_H_ */
