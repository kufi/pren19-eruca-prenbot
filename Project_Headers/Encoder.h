/*
 * Encoder.h
 *
 *  Created on: Dec 20, 2012
 *      Author: 8460p
 */

#ifndef ENCODER_H_
#define ENCODER_H_
#include "Cpu.h"

#define UMPROSTEP 1

int aA;
int aB;
int eA;
int eB;
int tikAarray[30];
int tiksA_am;
int tiksA;
int tiksB;
int tikBarray[30];
int tiksB_am;
int oldticksA;
int oldticksB;
uint32_t stepsA;
uint32_t stepsB;
int tiks;

LDD_TDeviceData *MyFakeEncoderRefrenzTimerPtr;

void startEncoding(void);
void stopEncoding(void);
uint32_t calcDistAmm(void);
uint32_t calcDistBmm(void);
void initEncoders(void);
void resetStepsA(void);
void resetStepsB(void);
void calcAritmeticMidleA(void);
void calcAritmeticMidleB(void);

#endif /* ENCODER_H_ */
