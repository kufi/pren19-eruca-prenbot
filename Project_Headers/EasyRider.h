/*
 * EasyRider.h
 *
 *  Created on: Feb 13, 2013
 *      Author: 8460p
 */

#ifndef EASYRIDER_H_
#define EASYRIDER_H_

int frekwentMotortestON;
int sAnswergenon;
int answerArrayAMidel[300];
int answerArrayActual[300];
int iAns;
int timeInMs;

void folowWall(int speed, int proxInMM, int deltaProx);
void stopCurve(int speed,char LorR , int AngleinSteps);
void remoteControll(void);
void runnline(int speedo);
void startRiding(void);
void testCalibratePID(int);
void testCalibratePID_MCStyle(int ,int );
void testMotor(void);
void testUS(void);
void generateStepAnswer(void);

#endif /* EASYRIDER_H_ */
