/*
 * motor_hRatio.c
 *
 *  Created on: Mar 8, 2013
 *      Author: 8460p
 */

#include "Cpu.h"
#include "Events.h"
#include "TU1.h"
#include "MotorA_PWM.h"
#include "PwmLdd1.h"
#include "MotorB_PWM.h"
#include "PwmLdd2.h"
#include "EncoderRefrenztimer.h"
#include "EncoderMotorA.h"
#include "ExtIntLdd1.h"
#include "EncoderMotorB.h"
#include "ExtIntLdd2.h"
#include "MotortreiberIN1_IN4.h"
#include "BitsIoLdd1.h"
#include "US_Triger.h"
#include "BitsIoLdd2.h"
#include "Lichtschranke.h"
#include "BitIoLdd1.h"
#include "LED1_4.h"
#include "BitsIoLdd3.h"
#include "BitsIoLdd4.h"
#include "RegelungReferenztimer.h"
#include "US_Referenztimer.h"
#include "I2C_Kompass.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "motor_HR.h"



void engineAForward_HR(void){
	MotortreiberIN1_IN4_SetBit(0);
	MotortreiberIN1_IN4_ClrBit(1);
}
void engineABackward_HR(void){
	MotortreiberIN1_IN4_SetBit(1);
	MotortreiberIN1_IN4_ClrBit(0);
}
void engineAStop_HR(void){
	MotortreiberIN1_IN4_SetBit(0);
	MotortreiberIN1_IN4_SetBit(1);
}
void engineBForward_HR(void){
	MotortreiberIN1_IN4_SetBit(2);
	MotortreiberIN1_IN4_ClrBit(3);
	}
void engineBbackward_HR(void){
	MotortreiberIN1_IN4_SetBit(3);
	MotortreiberIN1_IN4_ClrBit(2);
	}
void engineBStop_HR(void){
	MotortreiberIN1_IN4_SetBit(2);
	MotortreiberIN1_IN4_SetBit(3);
	}
void initalizeMotros_HR(void){
	engineAStop_HR();
	engineBStop_HR();
	MotorA_PWM_SetRatio16(0xFFFF);
	MotorB_PWM_SetRatio16(0xFFFF);
}
/**
 * sets the speed of the A Motor
 * 
 * @param [in] value
 *  +1..+255 => speed in forward direction
 *  -1..-255 => speed in backward direction
 *  0 => stop
 */
void setMotorA_HR(int value){
  if(0xFFFF<value){
	  value=0xFFFF;
  }
  if(value<-0xFFFF){
	  value=-0xFFFF;
  }
  if(value < 0)               // backward
  {
    engineABackward_HR();
    intensityEngineA_HR = -value;
    MotorA_PWM_SetRatio16(-((-value)-0xFFFF));
  }
  else if(value > 0)          // forward
  {
	engineAForward_HR();
	intensityEngineA_HR = value; 
	MotorA_PWM_SetRatio16(-(value-0xFFFF));
  } 
  else                        // stop
  {
   engineAStop_HR();
   intensityEngineA_HR = value;
   MotorA_PWM_SetRatio16(0xFFFF);
  }
  }

/**
 * sets the speed of the B Motor
 * 
 * @param [in] value
 *  +1..+255 => speed in forward direction
 *  -1..-255 => speed in backward direction
 *  0 => stop
 */
void setMotorB_HR(int value){
	if(0xFFFF<value){
		  value=0xFFFF;
	  }
	  if(value<-0xFFFF){
		  value=-0xFFFF;
	  }
	  if(value < 0)               // backward
	  {
	    engineBbackward_HR();
	    intensityEngineB_HR = -value;
	    MotorB_PWM_SetRatio16(-((-value)-0xFFFF));
	  }
	  else if(value > 0)          // forward
	  {
		engineBForward_HR();
		intensityEngineB_HR = value; 
		MotorB_PWM_SetRatio16(-(value-0xFFFF));
	  } 
	  else                        // stop
	  {
	   engineBStop_HR();
	   intensityEngineB_HR = value;
	   MotorB_PWM_SetRatio16(0xFFFF);
	  }
}
