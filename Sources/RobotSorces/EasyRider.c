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
#include "Raspberry_I2C.h"


void remoteControll(void){
	char actualOrder;
	int actualOrderValue;
	testCalibratePID(0);
	do{
	if(reciveFromPi(&actualOrder,&actualOrderValue)){
		if (actualOrder=='R'){
			PIDB_Testsollwert=	actualOrderValue-600;
		}
		if (actualOrder=='L'){
			PIDA_Testsollwert=	actualOrderValue-600;		
		}

		
	}
	}while(actualOrder!='S');
	PIDA_Testsollwert=0;
	PIDB_Testsollwert=0;
	
}





void testCalibratePID(int speed_){
	initPID(65535,38,0,380);
	initEncoders();
	regelverzoegerung=50;
	PIDA_Testsollwert= speed_;
	PIDB_Testsollwert= speed_;
	PIDA_Activated=1;
	PIDB_Activated=1;
	
	
	
}
void runnline(int speedo){
	testCalibratePID(speedo);
	for(;;){
		
		//PIDB_Testsollwert= (speedo*((int)(stepsA-stepsB)+100))/100;
		//if(PIDB_Testsollwert<0) PIDB_Testsollwert=0;
		PIDB_Testsollwert= (speedo*((int)(stepsA-stepsB)+100))/100;
		PIDA_Testsollwert= (speedo*(-((int)(stepsA-stepsB))+100))/100;
		if(PIDB_Testsollwert<speedo/2) PIDB_Testsollwert=speedo/2;
		if(PIDA_Testsollwert<speedo/2) PIDA_Testsollwert=speedo/2;
	}
}

void folowWall(int speed, int proxInMM, int deltaProx){
	int wertA, wertB, outbrakeClose = 0, outbrakeFar=0;
	initUS();
	freqwentMesuring();
	testCalibratePID(speed);
	while( (stepsA< 400000 ) || (distanceFront>400)){
	if(((int) distanceRechtsFront > (proxInMM+deltaProx)) || outbrakeFar){
		outbrakeFar=1;
		if(0>((int) distanceRechtsHeck-(int)distanceRechtsFront)){
		PIDA_Testsollwert=(speed*12)/10;
		PIDB_Testsollwert=(speed*10)/12;	
		}else{if(10>((int) distanceRechtsHeck-(int)distanceRechtsFront)){
		PIDA_Testsollwert=(speed*11)/10;
		PIDB_Testsollwert=(speed*10)/11;
		}else{
		 PIDA_Testsollwert=speed;
		 PIDB_Testsollwert=speed;
		}
		}
		if((int) distanceRechtsFront < proxInMM) outbrakeFar=0;
	}
	if(((int) distanceRechtsFront < (proxInMM-deltaProx))|| outbrakeClose){
	    outbrakeClose=1;
	    if(0>((int)distanceRechtsFront-(int)distanceRechtsHeck)){
	    PIDB_Testsollwert=(speed*12)/10;
	    PIDA_Testsollwert=(speed*10)/12;	
	    }else{if(10>((int)distanceRechtsFront-(int)distanceRechtsHeck)){
	    PIDB_Testsollwert=(speed*11)/10;
	    PIDA_Testsollwert=(speed*10)/11;	
	    }else{
	    PIDA_Testsollwert=speed;
	    PIDB_Testsollwert=speed;
	    }
	    }
	   
	    if((int)distanceRechtsFront>proxInMM) outbrakeClose=0;
	}
	if (!outbrakeFar&&!outbrakeClose){
	wertB= (speed*((((int)distanceRechtsHeck-(int)distanceRechtsFront))+100))/100;
	wertA= (speed*(((((int)distanceRechtsFront-(int)distanceRechtsHeck))+100)))/100;
	if(wertB<(speed*10)/13) wertB=(speed*10)/13;
	if(wertA<(speed*10)/13) wertA=(speed*10)/13;
	if(wertB*10>speed*12) wertB=(speed*12)/10;
	if(wertA*10>speed*12) wertA=(speed*12)/10;
	PIDB_Testsollwert=wertB;
	PIDA_Testsollwert=wertA;
	}
	}
	PIDB_Testsollwert=0;
	PIDA_Testsollwert=0;
}
void stopCurve(int speed,char LorR , int AngleinSteps){
	testCalibratePID(0);
	resetStepsA();
	resetStepsB();
	if(LorR=='R'){
		while(AngleinSteps>stepsA){
		PIDB_Testsollwert = 0;
		PIDA_Testsollwert = speed;
		}
		PIDA_Testsollwert = 0;
	}
	if(LorR=='L'){
		while(AngleinSteps>stepsB){
	    PIDB_Testsollwert = speed;
		PIDA_Testsollwert = 0;
		}
		PIDB_Testsollwert = 0;
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
