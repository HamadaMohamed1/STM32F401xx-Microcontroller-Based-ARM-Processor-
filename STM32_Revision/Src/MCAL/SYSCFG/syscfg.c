/*
 * syscfg.c
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */

/************************************** 	Includes                   		**************************************/
#include "../../../Inc/MCAL/SYSCFG/syscfg_interface.h"
/************************************** 	Function Definition		   		**************************************/
/**
 * @brief  : set external interrupt port to SYSCFG
 * @param  : (line)  @ref EXTI_LINE_t
 * @param  : (port)
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t syscfg_set_EXTI_port(EXTI_LINE_t line , uint8_t port)
{
	Std_RetType_t ret = RET_OK;
	if((line > EXTI_LINE15) || (port > 7))
	{
		ret= RET_ERROR;
	}
	else
	{
		uint8_t l_reg_number = (line / 4);
		uint8_t l_bits_number = (line % 4)*4;
		switch(l_reg_number)
		{
			case 0:
				SYSCFG->EXTICR0 &= ~(port << l_bits_number);	/*Clearing the required 4 bits*/
				SYSCFG->EXTICR0 |=  (port << l_bits_number);	/*Set the required value to 4 bits*/
			break;
			case 1:
				SYSCFG->EXTICR1 &= ~(port << l_bits_number);	/*Clearing the required 4 bits*/
				SYSCFG->EXTICR2 |=  (port << l_bits_number);	/*Set the required value to 4 bits*/
			break;
			case 2:
				SYSCFG->EXTICR2 &= ~(port << l_bits_number);	/*Clearing the required 4 bits*/
				SYSCFG->EXTICR2 |=  (port << l_bits_number);	/*Set the required value to 4 bits*/
			break;
			case 3:
				SYSCFG->EXTICR3 &= ~(port << l_bits_number);	/*Clearing the required 4 bits*/
				SYSCFG->EXTICR3 |=  (port << l_bits_number);	/*Set the required value to 4 bits*/
			break;
		}



	}
	return ret;
}

