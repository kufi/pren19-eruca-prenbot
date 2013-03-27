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





int reciveFromPi(char* comand, int* value){
	
	if(raspberryDataPtr->received == 1){
		      raspberryDataPtr->received = 0;
		      *comand = (char) *buffer;
			  *value = (((int)*(buffer + 1)) << 8 ) + (int)*(buffer + 2);
			  raspberryReceiveBlock();
			  return 1;
		  }
	return 0;	
}

int sendToPi(char* comand, int* value){
	int mask=0xFF;
	byte bytesToSend[3];
	
	bytesToSend[0]=(byte)*comand;
	bytesToSend[1]=(byte)(*value>>8);
    bytesToSend[2]= (byte) (*value & mask);
	raspberrySendBlock(bytesToSend);  
	//raspberryReceiveBlock(); Wird im sent event aufgerufen.
	return 1; //nur für evt. Fehlerkorektur 
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
