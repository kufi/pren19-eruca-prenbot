/*
 * Encoder.c
 *
 *  Created on: Feb 5, 2013
 *      Author: 8460p
 */
#include "Encoder.h"

void startEncoding(void){
	EncoderMotorA_Enable();
	EncoderMotorB_Enable();
}
void stopEncoding(void){
	EncoderMotorA_Disable();
	EncoderMotorB_Disable();
}
void initEncoders(void){
	tiksA_am=0xFFFF;
	tiksB_am=0xFFFF;
	resetStepsA();
	resetStepsB();
	startEncoding();
}

void calcAritmeticMidleA(void){
	
	if(tiksA_am<=50){
		tiksA_am=0xFFFF;
	}
}
void calcAritmeticMidleB(void){
	int summe,i=0;
	
	for(i;i<=aB;i++){
		summe += tikBarray[i];
	}
	tiksB_am=summe/(aB+1);
	aB=0;
	if(tiksB_am<=50){
		tiksB_am=0xFFFF;
	}
}
uint32_t calcDistAmm(void){
	return (stepsA*UMPROSTEP)/1000;
}
uint32_t calcDistBmm(void){
	return (stepsB*UMPROSTEP)/1000;
}
void resetStepsA(void){
	stepsA=0;
}
void resetStepsB(void){
	stepsB=0;
}

