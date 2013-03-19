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

void startRiding(void);
void testCalibratePID(void);
void testMotor(void);
void testUS(void);
void generateStepAnswer(void);

#endif /* EASYRIDER_H_ */
