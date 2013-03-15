/*
 * US.h
 *
 *  Created on: Feb 4, 2013
 *      Author: 8460p
 */

#ifndef US_H_
#define US_H_

#define DEVIDER 7642
#define APTASTRATE 3
#define DISTANCEOFFSET 60

#include "Cpu.h"

uint32_t distanceFront;
uint32_t distanceHeck;
uint32_t distanceRechtsFront;
uint32_t distanceRechtsHeck;

int bussy;
int actifUScomponent;
int freqwentUSactive;

uint32_t atual_US_ticks;
uint32_t timepast;
uint32_t old_US_ticks;
LDD_TDeviceData *MyFakeUSRefrenzTimerPtr;

void mesureUSFront(void);
void mesureUSHeck(void);
void mesureUSRechts_Front(void);
void mesureUSRechts_Heck(void);
void initUS(void);
void freqwentMesuring(void);

#endif /* US_H_ */
