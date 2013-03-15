/** ###################################################################
**     Filename    : Events.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2012-12-03, 21:43, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "I2cSlave.h"
#include "EncoderRefrenztimer.h"
#include "TU1.h"
#include "MotorA_PWM.h"
#include "MotorA_PWM.h"
#include "PwmLdd1.h"
#include "MotorB_PWM.h"
#include "MotorB_PWM.h"
#include "PwmLdd2.h"
#include "EncoderRefrenztimer.h"
#include "EncoderMotorA.h"
#include "ExtIntLdd1.h"
#include "EncoderMotorB.h"
#include "ExtIntLdd2.h"
#include "MotortreiberIN1_IN4.h"
#include "MotortreiberIN1_IN4.h"
#include "BitsIoLdd1.h"
#include "US_Triger.h"
#include "US_Triger.h"
#include "BitsIoLdd2.h"
#include "Lichtschranke.h"
#include "Lichtschranke.h"
#include "BitIoLdd1.h"
#include "LED1_4.h"
#include "LED1_4.h"
#include "BitsIoLdd3.h"
#include "IO_Res_Lueft.h"
#include "IO_Res_Lueft.h"
#include "BitsIoLdd4.h"
#include "RegelungReferenztimer.h"
#include "US_Referenztimer.h"
#include "I2C_Kompass.h"
#include "US_FrontListener.h"
#include "RegelungReferenztimer.h"
#include "US_Referenztimer.h"
#include "I2C_Kompass.h"
#include "US_FrontListener.h"
#include "ExtIntLdd4.h"
#include "US_Rechts_FrontListener.h"
#include "US_HeckListener.h"
#include "ExtIntLdd5.h"
#include "US_Rechts_HeckListener.h"
#include "US_Rechts_FrontListener.h"
#include "ExtIntLdd6.h"
#include "US_DachListener.h"
#include "US_Rechts_HeckListener.h"
#include "ExtIntLdd7.h"
#include "US_DachTrigger.h"
#include "ExtIntLdd3.h"
#include "US_HeckListener.h"
#include "BitIoLdd2.h"
#include "Start.h"
#include "EncoderMotorA.h"
#include "ExtIntLdd8.h"
#include "Stop.h"
#include "EncoderMotorB.h"
#include "ExtIntLdd9.h"
#include "PE_LDD.h"

void Cpu_OnNMIINT(void);
/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/


void EncoderRefrenztimer_OnChannel0(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  EncoderRefrenztimer_OnChannel0 (module Events)
**
**     Component   :  EncoderRefrenztimer [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel0 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void EncoderRefrenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  EncoderRefrenztimer_OnCounterRestart (module Events)
**
**     Component   :  EncoderRefrenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void EncoderMotorA_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EncoderMotorA_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorA [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void I2CKomunikation_PI_OnSlaveBlockSent(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnSlaveBlockSent (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         transmission of the data successfully. This event is not
**         available for the MASTER mode and if SlaveSendBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2CKomunikation_PI_OnSlaveBlockReceived(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnSlaveBlockReceived (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         reception of the data successfully. This event is not
**         available for the MASTER mode and if SlaveReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2CKomunikation_PI_OnError(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2CKomunikation_PI_OnError (module Events)
**
**     Component   :  I2CKomunikation_PI [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void EncoderMotorB_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EncoderMotorB_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorB [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void I2C_Kompass_OnMasterBlockSent(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C_Kompass_OnMasterBlockSent (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2C_Kompass_OnMasterBlockReceived(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C_Kompass_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2C_Kompass_OnError(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C_Kompass_OnError (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void US_Rechts_HeckListener_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  US_Rechts_HeckListener_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void US_Rechts_FrontListener_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  US_Rechts_FrontListener_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void US_HeckListener_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  US_HeckListener_OnInterrupt (module Events)
**
**     Component   :  US_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void US_FrontListener_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  US_FrontListener_OnInterrupt (module Events)
**
**     Component   :  US_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void US_Referenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  US_Referenztimer_OnCounterRestart (module Events)
**
**     Component   :  US_Referenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void RegelungReferenztimer_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  RegelungReferenztimer_OnCounterRestart (module Events)
**
**     Component   :  RegelungReferenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void ResInterrupt_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  ResInterrupt_OnInterrupt (module Events)
**
**     Component   :  ResInterrupt [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt2_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt2_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorB [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt1_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt1_OnInterrupt (module Events)
**
**     Component   :  EncoderMotorA [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Stop_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Stop_OnInterrupt (module Events)
**
**     Component   :  Stop [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Start_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Start_OnInterrupt (module Events)
**
**     Component   :  Start [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void US_DachListener_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  US_DachListener_OnInterrupt (module Events)
**
**     Component   :  US_DachListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt6_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt6_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt5_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt5_OnInterrupt (module Events)
**
**     Component   :  US_Rechts_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt4_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt4_OnInterrupt (module Events)
**
**     Component   :  US_HeckListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void EInt3_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  EInt3_OnInterrupt (module Events)
**
**     Component   :  US_FrontListener [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void I2C2_OnMasterBlockSent(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockSent (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2C2_OnMasterBlockReceived(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2C2_OnError(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2C2_OnError (module Events)
**
**     Component   :  I2C_Kompass [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void TU4_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  TU4_OnCounterRestart (module Events)
**
**     Component   :  US_Referenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void TU3_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  TU3_OnCounterRestart (module Events)
**
**     Component   :  RegelungReferenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void TU2_OnCounterRestart(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  TU2_OnCounterRestart (module Events)
**
**     Component   :  EncoderRefrenztimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2cSlave_OnSlaveBlockSent(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2cSlave_OnSlaveBlockSent (module Events)
**
**     Component   :  I2cSlave [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         transmission of the data successfully. This event is not
**         available for the MASTER mode and if SlaveSendBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2cSlave_OnSlaveBlockReceived(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2cSlave_OnSlaveBlockReceived (module Events)
**
**     Component   :  I2cSlave [I2C_LDD]
**     Description :
**         This event is called when I2C in slave mode finishes the
**         reception of the data successfully. This event is not
**         available for the MASTER mode and if SlaveReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

void I2cSlave_OnError(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Event       :  I2cSlave_OnError (module Events)
**
**     Component   :  I2cSlave [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
