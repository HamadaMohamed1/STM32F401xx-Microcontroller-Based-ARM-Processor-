/*
 * main.h
 *
 *  Created on: Mar 1, 2026
 *      Author: Hamada
 */

#ifndef MAIN_H_
#define MAIN_H_

/************************************** 	Includes                   		**************************************/
#include  <stdint.h>
#include "RCC.h"
#include "STM32F401xx.h"
#include "systick_interface.h"
#include "gpio_interface.h"
/************************************** 	Macro Declaration          		**************************************/
/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/
Std_RetType_t SystemClock_Config(void);

#endif /* MAIN_H_ */
