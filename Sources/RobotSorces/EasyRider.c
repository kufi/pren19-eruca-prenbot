/*
 * EasyRider.c
 *
 *  Created on: Feb 6, 2013
 *      Author: 8460p
 */
#include "US.h"
#include "Encoder.h"
#include "Motor.h"
#include "PID.h"
#include "EasyRider.h"
#include "MC_PID.h"


void startRiding(void){
	initUS();

	for(;;){
		
		
		
		
		
	}
}
void testCalibratePID_A(int Max,int pFacktor, int iFacktor, int dFacktor, int sollwert, int istwert){
	initPID(Max,pFacktor,iFacktor,dFacktor);
	initEncoders();
	regelverzoegerung=5;
	PIDA_Testsollwert= sollwert;
	PIDB_Testsollwert= sollwert;
	PIDA_Testistwert= istwert;
	PIDA_Activated=1;
	PIDB_Activated=1;
	
	
	
}
void testCalibratePID_MCStyle(int sr,int sl){
	initEncoders();
	regelverzoegerung=100;
	pidInit();
	pidSetSpeed(sr,sl);
}

void generateStepAnswer(void){
	timeInMs=2;
	sAnswergenon =1;
	setMotorA_HR(0xFFFF);
}



void testMotor(void){
	frekwentMotortestON =1;
	initUS();
	freqwentMesuring();
	initalizeMotros();
	
	
}
void testUS(void){
	initUS();
	freqwentMesuring();
}
