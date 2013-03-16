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

void initRaspberryI2C()
{
	commandLength = 3;
	buffer = (byte *)malloc(sizeof(byte) * commandLength);
	raspberryPtr = I2cSlave_Init(&raspberryDataPtr);
	raspberryReceiveBlock();
}

void raspberryReceiveBlock()
{
	I2cSlave_SlaveReceiveBlock(raspberryPtr, buffer, commandLength);
}

void raspberrySendBlock(LDD_TData *data, LDD_I2C_TSize size)
{
	I2cSlave_SlaveSendBlock(raspberryPtr, data, size);
}
