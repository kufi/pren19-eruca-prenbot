/*
 * MC_PID.h
 *
 *  Created on: Mar 18, 2013
 *      Author: 8460p
 */

#ifndef MC_PID_H_
#define MC_PID_H_

int pidEnabled;



void pidSetSpeedL(int speed);
void pidSetSpeedR(int speed);
void pidSetSpeed(int speedL, int speedR);
void pidDoWork(void);


void pidInit(void);
#endif /* MC_PID_H_ */
