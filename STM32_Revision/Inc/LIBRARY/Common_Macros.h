/*
 * Common_Macros.h
 *
 *  Created on: Mar 1, 2026
 *      Author: Hamada
 */

#ifndef LIBRARY_COMMON_MACROS_H_
#define LIBRARY_COMMON_MACROS_H_

/************************************** 	Includes                   		**************************************/
#include <stdint.h>
/************************************** 	Macro Declaration          		**************************************/
#define NULL					0
/************************************** 	Macro Function Declaration 		**************************************/
#define SET_BIT(REG,BIT)		((REG) |= (1<<BIT))         /*     0010 0000   */
#define CLEAR_BIT(REG,BIT)		((REG) &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)		((REG) ^= (1<<BIT))
#define READ_BIT(REG,BIT)		((REG)  & (1<<BIT))

#define WRITE_REG(REG,VALUE) 	((REG)  = (VALUE))
#define READ_REG(REG) 			((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) 	WRITE_REG((REG),((READ_REG(REG) & (~(CLEARMASK))) | (SETMASK)))
/*
 * How MODIFY_REG work?
 * if we need to modify the register X , and write this value (0xB = 1011) in the position (7:4)
 *
 * X = 0xF00FAB0F , First_Bit_POS = 4 , Value to be written = 0x000000B0
 *
 * SETMASK = Value to be written = 0x000000B0
 * CLEARMASK = 0xF << First_Bit_POS = 0xF << 4 = 0xF0
 * ~CLEARMASK = 0xFFFFFF0F
 * READ_REG(REG) = 0xF00FAB0F
 *
 * READ_REG(REG) & ~CLEARMASK = 0xF00FAB0F & 0xFFFFFF0F = 0xF00FAB0F
 *
 * (READ_REG(REG) & ~CLEARMASK) | (SETMASK) = 0xF00FAB0F | 0x000000B0 = 0xF00FABBF
 *
 *	WRITE_REG(REG,VALUE) = WRITE_REG(X,0xF00FABBF)
 *
 *	then register X has value = 0xF00FABBF
 *
 *  */






/************************************** 	Data Type Declaration      		**************************************/
typedef enum
{
	RET_OK 	  = 0x00,
	RET_ERROR = 0x01
}Std_RetType_t;
/************************************** 	Function Declaration	   		**************************************/



#endif /* LIBRARY_COMMON_MACROS_H_ */
