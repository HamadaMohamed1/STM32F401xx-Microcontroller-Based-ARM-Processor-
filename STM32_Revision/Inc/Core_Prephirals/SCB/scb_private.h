/*
 * scb_private.h
 *
 *  Created on: Mar 8, 2026
 *      Author: Hamada
 */

#ifndef CORE_PREPHIRALS_SCB_SCB_PRIVATE_H_
#define CORE_PREPHIRALS_SCB_SCB_PRIVATE_H_

/************************************** 	Includes                   		**************************************/
#include  "LIBRARY/STM32F401xx.h"
#include "LIBRARY/Common_Macros.h"
/************************************** 	Macro Declaration          		**************************************/
#define GROUP_PRIORITIES_16_SUB_PRIORITIES_NONE			0X05FA0000UL
#define GROUP_PRIORITIES_8_SUB_PRIORITIES_2 			0X05FA0400UL
#define GROUP_PRIORITIES_4_SUB_PRIORITIES_4 			0X05FA0500UL
#define GROUP_PRIORITIES_2_SUB_PRIORITIES_8 			0X05FA0600UL
#define GROUP_PRIORITIES_1_SUB_PRIORITIES_16			0X05FA0700UL

/**
 * 				4.4.5 Application interrupt and reset control register (AIRCR)
 * 				Bits 31:16 VECTKEYSTAT/ VECTKEY Register , write 0x5FA to VECTKEY, otherwise the write is ignored
 * 				Bits 10:8 PRIGROUP: Interrupt priority grouping field
 *				Example:
 * 				00000000 00000000   00000 "101" 00000000
 * 				00000101 11111010   00000 "00"  00000000
 * 			0x  05       fa         05      	00       => 0x05fa0500  then 4 groups & 4 sub
 *
 * /




/******System handler control and state register (SHCSR)     Required privilege *******/
#define USAGE_FAULT_ENABLE_BIT_POS 						(18)
#define BUS_FAULT_ENABLE_BIT_POS 						(17)
#define MEMORY_MANAGE_FAULT_ENABLE_BIT_POS 				(16)

#define SVC_CALL_PENDING_BIT_POS 						(15)  /*SVCALLPENDED: SVC call pending bit, reads as 1 if exception is pending (2)*/
#define BUS_FAULT_PENDING_BIT_POS 						(14)  /* BUSFAULTPENDED: Bus fault exception pending bit, reads as 1 if exception is pending (2)*/
#define MEM_MANAGE_PENDING_BIT_POS 						(13)  /*MEMFAULTPENDED: Memory management fault exception pending bit, reads as 1 if exception is pending (2)*/
#define USAGE_FAULT_PENDNIG_BIT_POS  					(12)  /* USGFAULTPENDED: Usage fault exception pending bit, reads as 1 if exception is pending (2*/
#define SYSTICK_ACTIVE_BIT_POS 							(11)  /* SYSTICKACT: SysTick exception active bit, reads as 1 if exception is active (3*/
#define PENDSV_ACTIVE_BIT_POS	 						(10)  /*PENDSVACT: PendSV exception active bit, reads as 1 if exception is activ*/
#define MONITOR_ACTIVE_BIT_POS 							(8)   /*MONITORACT: Debug monitor active bit, reads as 1 if Debug monitor is active*/
#define SVCALL_ACTIVE_BIT_POS 							(7)	  /*SVCALLACT: SVC call active bit, reads as 1 if SVC call is activ*/
#define USAGE_FAULT_ACTIVE_BIT_POS 						(3)	  /*USGFAULTACT: Usage fault exception active bit, reads as 1 if exception is activ*/
#define BUS_FAULT_ACTIVE_BIT_POS 						(1)   /* BUSFAULTACT: Bus fault exception active bit, reads as 1 if exception is activ*/
#define MEMORY_FAULT_ACTIVE_BIT_POS 					(0)   /* MEMFAULTACT: Memory management fault exception active bit, reads as 1 if exception is active*/





/************************************** 	Macro Function Declaration 		**************************************/
/************************************** 	Data Type Declaration      		**************************************/
/************************************** 	Function Declaration	   		**************************************/


#endif /* CORE_PREPHIRALS_SCB_SCB_PRIVATE_H_ */
