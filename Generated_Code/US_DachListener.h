/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : US_DachListener.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt
**     Version     : Component 02.104, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-15, 11:32, # CodeGen: 11
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : INT_PORTD
**         User handling procedure     : US_DachListener_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       77            |  PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4
**             ----------------------------------------------------
**
**         Port name                   : PTD
**
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**
**         Signal edge/level           : falling
**         Priority                    : 2
**         Pull option                 : off
**         Initial state               : Disabled
**
**
**         Port data register          : GPIOD_PDOR [0x400FF0C0]
**         Port control register       : GPIOD_PDDR [0x400FF0D4]
**     Contents    :
**         Enable  - void US_DachListener_Enable(void);
**         Disable - void US_DachListener_Disable(void);
**         GetVal  - bool US_DachListener_GetVal(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __US_DachListener_H
#define __US_DachListener_H

/* MODULE US_DachListener. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "ExtIntLdd7.h"

#include "Cpu.h"




/*
** ===================================================================
**     Method      :  US_DachListener_Enable (component ExtInt)
**
**     Description :
**         Enable the component - the external events are accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define US_DachListener_Enable() (ExtIntLdd7_Enable(ExtIntLdd7_DeviceData))

/*
** ===================================================================
**     Method      :  US_DachListener_Disable (component ExtInt)
**
**     Description :
**         Disable the component - the external events are not accepted.
**         This method is available only if HW module allows
**         enable/disable of the interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define US_DachListener_Disable() (ExtIntLdd7_Disable(ExtIntLdd7_DeviceData))

/*
** ===================================================================
**     Method      :  US_DachListener_GetVal (component ExtInt)
**
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
#define US_DachListener_GetVal() (ExtIntLdd7_GetVal(ExtIntLdd7_DeviceData))

void ExtIntLdd7_OnInterrupt(LDD_TUserData *UserDataPtr);

/* END US_DachListener. */

#endif 
/* ifndef __US_DachListener_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
