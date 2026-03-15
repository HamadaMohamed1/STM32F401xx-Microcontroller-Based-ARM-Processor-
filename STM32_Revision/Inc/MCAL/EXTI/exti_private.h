/*
 * exti_private.h
 *
 *  Created on: Mar 15, 2026
 *      Author: Hamada
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

/************************************** 	Includes                   		**************************************/
#include "../../LIBRARY/Common_Macros.h"
#include "../../LIBRARY/STM32F401xx.h"
/************************************** 	Macro Declaration          		**************************************/
#define EXTI_MAX_NUMBER			23

#define EXTI_DISABLE 			0
#define EXTI_ENABLE 			1
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
typedef enum
{
	EXTI_0 =0,
	EXTI_1 ,
	EXTI_2 ,
	EXTI_3 ,
	EXTI_4 ,
	EXTI_5 ,
	EXTI_6 ,
	EXTI_7 ,
	EXTI_8 ,
	EXTI_9 ,
	EXTI_10 ,
	EXTI_11 ,
	EXTI_12 ,
	EXTI_13 ,
	EXTI_14 ,
	EXTI_15 ,
	EXTI_16 ,
	EXTI_17 ,
	EXTI_18 ,
	//EXTI_19 , reserved
	//EXTI_20 , reserved
	EXTI_21 = 21,
	EXTI_22 = 22,
}EXTI_source_t;


typedef enum
{
	RISING_EDGE = 0 ,
	FALLING_EDGE ,
	RISING_FALLING_EDGE ,
}EXTI_edge_t;


typedef enum
{
	INT_NOT_TRIGGERED = 0 ,
	INT_TRIGGERED ,
}pending_flag_t;



/************************************** 	Function Declaration	   		**************************************/


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
