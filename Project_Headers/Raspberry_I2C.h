/*
 * Raspberry_I2C.h
 *
 *  Created on: Mar 13, 2013
 *      Author: Admin
 */

#ifndef RASPBERRY_I2C_H_
#define RASPBERRY_I2C_H_

struct Raspberry_
{
	int received;
	int error;
};

typedef struct Raspberry_ Raspberry;
typedef Raspberry *RaspberryPtr;
RaspberryPtr initRaspberryI2C();
void raspberryReceiveBlock();
void raspberrySendBlock(byte *bytes);
RaspberryPtr getRaspberryDataPtr();
byte *getRaspberryBuffer();

#endif /* RASPBERRY_I2C_H_ */
