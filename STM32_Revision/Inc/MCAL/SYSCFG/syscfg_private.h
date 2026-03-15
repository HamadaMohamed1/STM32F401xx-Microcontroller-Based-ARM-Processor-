/*
 * syscfg_private.h
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */

#ifndef MCAL_SYSCFG_SYSCFG_PRIVATE_H_
#define MCAL_SYSCFG_SYSCFG_PRIVATE_H_

/************************************** 	Includes                   		**************************************/
#include "../../LIBRARY/STM32F401xx.h"
#include "../../LIBRARY/Common_Macros.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
typedef enum
{
	EXTI_LINE0=0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15
}EXTI_LINE_t;
/************************************** 	Function Declaration	   		**************************************/

#endif /* MCAL_SYSCFG_SYSCFG_PRIVATE_H_ */
