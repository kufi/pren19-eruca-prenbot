/*
 * US.c
 *
 *  Created on: Feb 4, 2013
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
#include "US.h"


void mesureUSFront(void){
	actifUScomponent= 1;
	bussy = 1;
	US_FrontListener_Enable();
	US_Triger_ClrBit(0);
	old_US_ticks=US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
}

void mesureUSHeck(void){
	actifUScomponent= 2;
	bussy = 1;
	US_HeckListener_Enable();
	US_Triger_ClrBit(1);
	old_US_ticks=US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
}
void mesureUSRechts_Front(void){
	actifUScomponent= 3;
	bussy = 1;
	US_Rechts_FrontListener_Enable();
	US_Triger_ClrBit(2);
	old_US_ticks=US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
}
void mesureUSRechts_Heck(void){
	actifUScomponent= 4;
	bussy = 1;
	US_Rechts_HeckListener_Enable();
	US_Triger_ClrBit(3);
	old_US_ticks=US_Referenztimer_GetCounterValue(MyFakeUSRefrenzTimerPtr);
}
void freqwentMesuring(void){
	actifUScomponent= 1;
	bussy = 0;
	freqwentUSactive=1;
}
void initUS(void){
	freqwentUSactive=0;
	actifUScomponent=0;
}




