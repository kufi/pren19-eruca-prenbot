/*
 * I2C.c
 *
 *  Created on: Mar 13, 2013
 *      Author: Admin
 */
#include "I2cSlave.h"
#include "Raspberry_I2C.h"
#include "PE_Types.h"
#include "PE_LDD.h"
#include "cstdlib"

LDD_TDeviceData *raspberryPtr;
byte *buffer;
RaspberryPtr raspberryDataPtr;
int commandLength;

RaspberryPtr initRaspberryI2C()
{
	commandLength = 3;
	buffer = (byte *)malloc(sizeof(byte) * commandLength);
	
	raspberryDataPtr = (RaspberryPtr)malloc(sizeof(Raspberry));
	raspberryDataPtr->received = 0;
	raspberryDataPtr->error = 0;
	raspberryPtr = I2cSlave_Init(raspberryDataPtr);
	raspberryReceiveBlock();
	return raspberryDataPtr;
}

RaspberryPtr getRaspberryDataPtr()
{
	return raspberryDataPtr;
}

byte *getRaspberryBuffer()
{
	return buffer;
}

void raspberryReceiveBlock()
{
	I2cSlave_SlaveReceiveBlock(raspberryPtr, buffer, commandLength);
}

void raspberrySendBlock(byte *bytes)
{
	I2cSlave_SlaveSendBlock(raspberryPtr, bytes, 3);
}
