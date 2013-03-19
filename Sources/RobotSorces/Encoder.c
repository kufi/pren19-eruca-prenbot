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
	tiksA_am=2000;
	tiksB_am=2000;
	resetStepsA();
	resetStepsB();
	startEncoding();
}


void calcAritmeticMidleA(void){
	int summe=0,i=0;
	
	if(aA<1){
		tiksA_am=tiksA;
	}else{
	for(i;i<aA;i++){
	 summe += tikAarray[i];
	}
	tiksA_am=summe/(aA);
	aA=0;
	}
	if(tiksA_am<50){
		tiksA_am=9999;
	 }
}
void calcAritmeticMidleB(void){
	int summe=0,i=0;
	
	for(i;i<=aB;i++){
		summe += tikBarray[i];
	}
	tiksB_am=summe/(aB+1);
	aB=0;
	//if(tiksB_am<=20){
	//	tiksB_am=2000;
	//}
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

