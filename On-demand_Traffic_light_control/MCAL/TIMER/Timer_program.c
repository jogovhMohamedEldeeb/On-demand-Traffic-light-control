/*
 * Timer_program.c
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */





#include "Timer_interface.h"


static void (*tmr0_overFlow_interruptHandler)(void);
static void (*tmr0_OC_interruptHandler)(void);


/**
 *
 * @param timer_0 Pointer to the TIMER 0 configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_init(const ST_timer0_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(timer_0->mode)
		{
			case TIMER0_NOTMAL_MODE :
				CLR_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
				break;

			case TIMER0_PHASS_CORRECT_MODE :
				SET_BIT(TCCR0,WGM00);
				CLR_BIT(TCCR0,WGM01);
				break;

			case TIMER0_CTC_MODE :
				CLR_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
				break;

			case TIMER0_FAST_PWM_MODE :
				SET_BIT(TCCR0,WGM00);
				SET_BIT(TCCR0,WGM01);
				break;
		}

		tmr0_overFlow_interruptHandler = timer_0->TIMER0_OV_interruptHandler;
		tmr0_OC_interruptHandler = timer_0->TIMER0_OC_interruptHandler;

		SET_PERSCALLEER(timer_0->prescaller);

		SET_OCO_MODE(timer_0->ocMode);

		if(timer_0->ocMode != OCO_DISCONNECTED)
		{
			SET_BIT(DDRB,3);
		}
	}
	return ret;
}



/**
 *
 * @param timer_0 the value to be written at TCCN0 register
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_Write_Value(uint8_t timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 > 255)
	{
		ret = E_NOT_OK;
	}
	else
	{
		TCNT0 =  timer_0;
	}
	return ret;
}



/**
 *
 * @param timer_0 Pinter to the value which written at TCCN0 register
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_Read_Value(uint8_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		*timer_0 = TCNT0;
	}
	return ret;
}



/**
 *
 * @param timer_0 Pointer to the TIMER 0 configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_OverFlow_Iterrupt_Enable(const ST_timer0_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		tmr0_overFlow_interruptHandler = timer_0->TIMER0_OV_interruptHandler;
		TIMER0_OVERFLOW_INTERRUPT_ENABLE();
	}
	return ret;
}



/**
 *
 * @param timer_0 Pointer to the TIMER 0 configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_OverFlow_Iterrupt_Disable(const ST_timer0_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		tmr0_overFlow_interruptHandler = NULL;
		TIMER0_OVERFLOW_INTERRUPT_DISABLE();
	}
	return ret;
}


/**
 *
 * @param timer_0 Pointer to the TIMER 0 configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_OC_Iterrupt_Enable(const ST_timer0_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		tmr0_OC_interruptHandler = timer_0->TIMER0_OC_interruptHandler;
		TIMER0_OC_INTERRUPT_ENABLE();
	}
	return ret;
}



/**
 *
 * @param timer_0 Pointer to the TIMER 0 configurations
 * @return Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
Std_ReturnType TMR0_OC_Iterrupt_Disnable(const ST_timer0_t* timer_0)
{
	Std_ReturnType ret = E_OK;
	if(timer_0 == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		tmr0_OC_interruptHandler = NULL;
		TIMER0_OC_INTERRUPT_DISABLE();
	}
	return ret;
}



ISR(TIMER0_OVF_vect)
{
	if(tmr0_overFlow_interruptHandler != NULL)
	{
		tmr0_overFlow_interruptHandler();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(tmr0_OC_interruptHandler != NULL)
	{
		tmr0_OC_interruptHandler();
	}
}

/*
-delay = 2^8 -(Fcpu / prescaler * Time delay)
-delay =  256 - ( 8MHZ / 8 * 5KHZ )= 256 - 200 = 56
*/

/* - Overflow_Time = (Prescaler_Value * 256) / Clock_Frequency
   - Number_of_Overflows = Delay_Time / Overflow_Time
  */
/* EX :
 	 Clock Frequency: 8 MHz
 	 Prescaler: 8
 	 Desired Delay: 5 seconds
 	 Overflow Time: (8 * 256) / 8000000 = 0.000256
 	 Overflows Needed: 5 /  0.000256 = 19,531.25
   */
void delay5s()
{
	/* normal mode */
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);

	SET_PERSCALLEER(TIMER0_8_PRESCALER);

	TCNT0 = 56;

	for(uint16 i=0 ; i<25000 ; i++)
	{
		while(TCNT0);
		TCNT0 = 56;
	}
}
