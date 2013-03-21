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
void testCalibratePID(){
	initPID(65535,760,0,7600);
	initEncoders();
	regelverzoegerung=10;
	PIDA_Testsollwert= 30;
	PIDB_Testsollwert= 30;
	PIDA_Activated=1;
	PIDB_Activated=1;
	
	
	
}
void runnline(int speedo){
	int difwert;
	initPID(65535,760,0,7600);
    initEncoders();
	regelverzoegerung=10;
	PIDA_Testsollwert= speedo;
	PIDB_Testsollwert= speedo;
	PIDA_Activated=1;
	PIDB_Activated=1;
	for(;;){
		
		//PIDB_Testsollwert= (speedo*((int)(stepsA-stepsB)+100))/100;
		//if(PIDB_Testsollwert<0) PIDB_Testsollwert=0;
		PIDB_Testsollwert= (speedo*((int)(stepsA-stepsB)+100))/100;
		PIDA_Testsollwert= (speedo*(-((int)(stepsA-stepsB))+100))/100;
		if(PIDB_Testsollwert<speedo/2) PIDB_Testsollwert=speedo/2;
		if(PIDA_Testsollwert<speedo/2) PIDA_Testsollwert=speedo/2;
	}
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
