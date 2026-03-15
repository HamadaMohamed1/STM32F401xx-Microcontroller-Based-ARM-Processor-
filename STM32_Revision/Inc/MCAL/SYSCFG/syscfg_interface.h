/*
 * syscfg_interface.h
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */

#ifndef MCAL_SYSCFG_SYSCFG_INTERFACE_H_
#define MCAL_SYSCFG_SYSCFG_INTERFACE_H_

/************************************** 	Includes                   		**************************************/
#include "syscfg_private.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : set external interrupt port to SYSCFG
 * @param  : (line)  @ref EXTI_LINE_t
 * @param  : (port)
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t syscfg_set_EXTI_port(EXTI_LINE_t line , uint8_t port);


#endif /* MCAL_SYSCFG_SYSCFG_INTERFACE_H_ */
