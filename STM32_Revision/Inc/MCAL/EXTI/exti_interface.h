/*
 * exti_interface.h
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/************************************** 	Includes                   		**************************************/
#include "exti_private.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
typedef struct
{
	void (* exti_handler)(void);
	EXTI_source_t source;
	EXTI_edge_t   edge;
}exti_config_t;
/************************************** 	Function Declaration	   		**************************************/
/**
 * @brief  : Initialize the external interrupt pin
 * @param  : (EXTI_object) pointer to configuration @ref EXTI_config_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_initialize(const exti_config_t* EXTI_object);
/**
 * @brief  : Enable interrupt to specific pin
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_enable(EXTI_source_t EXTI_source);
/**
 * @brief  : Disable interrupt to specific pin
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_disable(EXTI_source_t EXTI_source);
/**
 * @brief  : Set pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_set_pending_flag(EXTI_source_t EXTI_source);
/**
 * @brief  : Clear pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_clear_pending_flag(EXTI_source_t EXTI_source);
/**
 * @brief  : Read pending flag of external interrupt
 * @param  : (EXTI_source) interrupt source pin @ref EXTI_source_t
 * @param  : (pending_flag) pointer to store the flag's value  @ref pending_flag_t
 * @return :
 * 			(RET_OK) : The function done successfully
 * 			(RET_ERROR) : The function has a problem to perform this action
 */
Std_RetType_t exti_read_pending_flag(EXTI_source_t EXTI_source, pending_flag_t* pending_flag);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
