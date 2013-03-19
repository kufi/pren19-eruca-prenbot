/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         PI control
 * \file
 * \author        Christian Jost
 * \date          21.11.2012
 *
 * \b Language:   Ansi-C \n\n
 * \b Target:     MC Car \n
 *
 * $Id: pid.c 414 2012-12-02 14:23:48Z zajost $
 *--------------------------------------------------------------------
 */

#include "motor_HR.h"
#include "stdlib.h"
#include "MC_PID.h"
#include "Encoder.h"



static int setValueL, setValueOldL;
static int setValueR, setValueOldR;

static int kpL, kiL, kdL;
static int kpR, kiR, kdR;

static int integL;
static int integR;

static int devOldL;
static int devOldR;

static int delay=0;

static int devL, valL;
static int devR, valR;

void pidSetSpeedL(int speed)
{
  setValueL = speed;
}

void pidSetSpeedR(int speed)
{
  setValueR = speed;
}

void pidSetSpeed(int speedL, int speedR)
{
  setValueL = speedL;
  setValueR = speedR;
}

void pidDoWork(void)
{  
  
  if (delay > 0)
  {
    delay--;
    return;
  }
  
  if (setValueOldL == 0 && setValueL != 0)
  {
    delay = 2;
  }
  setValueOldL = setValueL;
  
  
  // left wheel
  if (setValueL == 0) valL = integL = devOldL = 0;
  else
  {
    // deviation (max devL = +1000 - -1000 = 2000)
    devL = -((setValueL - tiksA_am) / 8);
    if(devL>1000) devL=1000;
    if(devL<-1000) devL=-1000;
    // P-Part (max kpL = 
    valL = (kpL * devL) / 32;
    
    // I-Part with anti-windup
    if (kiL != 0) integL += devL;    
    valL += (kiL * integL) / 32;
    
    // D-Part
    valL += (kdL*(devL-devOldL)/32);
    devOldL = devL;
    
    // limit control point
    if (valL > 127)
    {
      valL = 127;
      integL -= devL;
    }
    else if (valL < -127)
    {
      valL = -127;
      integL -= devL;
    }
  }

  // right wheel
  if (setValueR == 0) valR = integR = devOldR = 0;
  else
  {
    // control deviation 
    devR = -((setValueR - tiksB_am) / 8);
    if(devR>1000) devR=1000;
    if(devR<-1000) devR=-1000;
    
    // P-Part
    valR = (kpR * devR) / 32;
    
    // I-Part  with anti-windup
    if (kiR != 0) integR += devR;
    valR += (kiR * integR) / 32;

    // D-Part
    valR += (kdR*(devR-devOldR)/32);
    devOldR = devR;
        
    // limit control point
    if (valR > 127)
    {
      valR = 127;
      integR -= devR;
    }
    else if (valR < -127)
    {
      valR = -127;
      integR -= devR;
    }
  }
  if (pidEnabled)
  {
	  
	setMotorA_HR(valL*50);
	setMotorB_HR(valR*50);
    
  }
}




void pidInit(void)
{
  setValueL = setValueR = 0;
  setValueOldL = setValueOldR = 0;
  
  integL = integR = 0;
  devOldL = devOldR = 0;
  
  pidEnabled = 1;
  
  kiL = kiR = 15; // max 20 
  kpL = kpR = 100; // max 128
  kdL = kdR = 6; // max 40
}
