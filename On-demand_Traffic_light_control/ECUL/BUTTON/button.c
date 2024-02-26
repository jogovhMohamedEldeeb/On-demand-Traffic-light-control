/*
 * button.c
 *
 *  Created on: 12 Dec 2023
 *      Author: mohamed_eldeeb
 */
#include "button.h"

 Std_ReturnType  BUTTON_init(const ST_buton_t *button)
 {
	 Std_ReturnType ret = E_OK;
	 if(button == NULL)
	 {
		 ret = E_NOT_OK;
	 }
	 else
	 {
		  DIO_pin_dirction_init(&(button->pin));
	 }
	 return ret;
 }

Std_ReturnType BUTTON_read(const ST_buton_t *button,EN_buttonState *btn_state)
{
	 Std_ReturnType ret = E_OK;
	 EN_logic_t pin_logic = DIO_LOW;
	 if(button == NULL && btn_state == NULL)
	 {
		 ret = E_NOT_OK;
	 }
	 else
	 {
		 DIO_read_logic(&(button->pin),&pin_logic);
		 if(button->connection == PULL_DOWN)
		 {
			 if(pin_logic == DIO_HIGH)
			 {
				 *btn_state = PRESSED;
			 }
			 else if(pin_logic == DIO_LOW)
			 {
				 *btn_state = RELEASSED;
			 }
			 else{/* nothing */  }
		 }
		 else if(button->connection == PULL_UP)
		 {
		 	 if(pin_logic == DIO_HIGH)
		 	 {
		 		 *btn_state = RELEASSED;
		 	 }
		 	 else if(pin_logic == DIO_LOW)
		 	 {
		 		 *btn_state = PRESSED;
		 	 }
		 	 else{ /* nothing */  }
		 }
		 else{ /* nothing */  }
		 ret = E_OK;
	 }
	 return ret;
}
