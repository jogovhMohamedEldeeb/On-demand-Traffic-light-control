/*
 * BIT_MATH.h
 *
 *  Created on: 11 Dec 2023
 *      Author: mohamed_eldeeb
 */

#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_
#include "STD_TYPES.h"

#define			MASK_PIN			1


#define	SET_BIT(_REG,PIN)			(_REG = _REG | (MASK_PIN<<PIN))
#define	CLR_BIT(_REG,PIN)			(_REG = _REG & (~(MASK_PIN<<PIN)))
#define	TOGGLE_BIT(_REG,PIN)		(_REG = _REG ^ (MASK_PIN<<PIN))
#define	READ_BIT(_REG,PIN)			((_REG>>PIN)  & MASK_PIN)


#define NULL	0

/* Variadic function to call any ISR */
#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#endif /* UTILS_BIT_MATH_H_ */
