/*
 * motor.c
 *
 *  Created on: Dec 20, 2012
 *      Author: 8460p
 */
/* Including needed modules to compile this module/procedure */
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
#include "Motor.h"



void engineAForward(void){
	MotortreiberIN1_IN4_SetBit(0);
	MotortreiberIN1_IN4_ClrBit(1);
}
void engineABackward(void){
	MotortreiberIN1_IN4_SetBit(1);
	MotortreiberIN1_IN4_ClrBit(0);
}
void engineAStop(void){
	MotortreiberIN1_IN4_SetBit(0);
	MotortreiberIN1_IN4_SetBit(1);
}
void engineBForward(void){
	MotortreiberIN1_IN4_SetBit(2);
	MotortreiberIN1_IN4_ClrBit(3);
	}
void engineBbackward(void){
	MotortreiberIN1_IN4_SetBit(3);
	MotortreiberIN1_IN4_ClrBit(2);
	}
void engineBStop(void){
	MotortreiberIN1_IN4_SetBit(2);
	MotortreiberIN1_IN4_SetBit(3);
	}
void initalizeMotros(void){
	engineAStop();
	engineBStop();
	MotorA_PWM_SetRatio8(255);
	MotorB_PWM_SetRatio8(255);
}
/**
 * sets the speed of the A Motor
 * 
 * @param [in] value
 *  +1..+255 => speed in forward direction
 *  -1..-255 => speed in backward direction
 *  0 => stop
 */
void setMotorA(int value){
  if(255<value){
	  value=254;
  }
  if(value<-255){
	  value=-254;
  }
  if(value < 0)               // backward
  {
    engineABackward();
    intensityEngineA = -value;
    MotorA_PWM_SetRatio8(-((-value)-255));
  }
  else if(value > 0)          // forward
  {
	engineAForward();
	intensityEngineA = value; 
	MotorA_PWM_SetRatio8(-(value-255));
  } 
  else                        // stop
  {
   engineAStop();
   intensityEngineA = value;
   MotorA_PWM_SetRatio8(255);
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
void setMotorB(int value){
  if(255>value && value>-255){
  if(value < 0)               // backward
  {
    engineBbackward();
    intensityEngineB = -value;
    MotorB_PWM_SetRatio8(-((-value)-255));
  }
  else if(value > 0)          // forward
  {
	engineBForward();
	intensityEngineB = value;
	MotorB_PWM_SetRatio8(-(value-255));
  } 
  else                        // stop
  {
   engineBStop();
   intensityEngineB = value;
   MotorB_PWM_SetRatio8(255);
  }
  }
}
