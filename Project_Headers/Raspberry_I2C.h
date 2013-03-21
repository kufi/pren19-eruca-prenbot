/*
 * Raspberry_I2C.h
 *
 *  Created on: Mar 13, 2013
 *      Author: Admin
 */

#ifndef RASPBERRY_I2C_H_
#define RASPBERRY_I2C_H_

typedef struct Raspberry_
{
	int received;
	void (*functionPtr)();
} Raspberry, *RaspberryPtr;

RaspberryPtr initRaspberryI2C();
void raspberryReceiveBlock();
RaspberryPtr getRaspberryDataPtr();
byte *getRaspberryBuffer();

#endif /* RASPBERRY_I2C_H_ */
