/*
 * systick_interface.h
 *
 *  Created on: Mar 5, 2026
 *      Author: Hamada
 */

#ifndef CORE_PREPHIRALS_SYSTICK_INTERFACE_H_
#define CORE_PREPHIRALS_SYSTICK_INTERFACE_H_

/************************************** 	Includes                   		**************************************/
#include "systick_private.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : Initialize the Systick timer
 * @param  :
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t systick_init(void);
/**
 * @brief  : systick_wait_blocking
 * @param  : (no_ticks) : number of ticks
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t systick_wait_blocking(uint32_t no_ticks);
/**
 * @brief  : Delay with Blocking
 * @param  : (ms) : number of Millie seconds
 * @return :
 *
 */
void delay_ms(uint32_t ms);
/**
 * @brief  : Delay with Blocking
 * @param  : (us) : number of micro seconds
 * @return :
 *
 */
void delay_us(uint32_t us);



#endif /* CORE_PREPHIRALS_SYSTICK_INTERFACE_H_ */
