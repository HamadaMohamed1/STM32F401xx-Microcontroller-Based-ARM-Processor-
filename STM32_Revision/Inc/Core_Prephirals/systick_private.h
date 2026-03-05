/*
 * systick_private.h
 *
 *  Created on: Mar 5, 2026
 *      Author: Hamada
 */

#ifndef CORE_PREPHIRALS_SYSTICK_PRIVATE_H_
#define CORE_PREPHIRALS_SYSTICK_PRIVATE_H_

/************************************** 	Includes                   		**************************************/
#include "../LIBRARY/Common_Macros.h"
#include "../LIBRARY/STM32F401xx.h"

/************************************** 	Macro Declaration          		**************************************/
#define SYSTICK_CLOCK_SOURCE_DIV_1 			0U
#define SYSTICK_CLOCK_SOURCE_DIV_8 			1U

#define SYSTICK_CLOCK_SOURCE	 			(SYSTICK_CLOCK_SOURCE_DIV_1)


#define STSTICK_LOAD_VALUE_POS				1U
#define STSTICK_LOAD_VALUE_ACCESS			24U


#define SYSTICK_CSR_ENABLE_POS 				0U
#define SYSTICK_CSR_ENABLE_MASK 			1U


#define SYSTICK_CSR_CLOCK_POS 				2U
#define SYSTICK_CSR_CLOCK_MASK				1U

#define SYSTICK_CSR_COUNTFLAG_POS 			16U
#define SYSTICK_CSR_COUNTFLAG_MASK			1U


/************************************** 	Macro Declaration          		**************************************/
#if SYSTICK_CLOCK_SOURCE==SYSTICK_CLOCK_SOURCE_DIV_1
#define F_CPU           16000000UL
#elif SYSTICK_CLOCK_SOURCE==SYSTICK_CLOCK_SOURCE_DIV_8
#define F_CPU           2000000UL
#else
#endif
#define TICKS_PER_MS    	((F_CPU / 1000) - 1)   		  // = 15,999
#define TICKS_PER_US        ((F_CPU / 1000000UL) - 1)     // 15  (1µs)
#define TICKS_PER_10US      ((F_CPU / 100000UL) - 1)      // 159 (10µs)




/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/


#endif /* CORE_PREPHIRALS_SYSTICK_PRIVATE_H_ */
