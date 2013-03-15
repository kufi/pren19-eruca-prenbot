/*
 * PID_A.h
 *
 *  Created on: Feb 21, 2013
 *      Author: 8460p
 */

#ifndef PID_A_H_
#define PID_A_H_
//Werte allgemein

int regelverzoegerung;
static int PIDinterruptCounter;

//Werte für PIDA

int PIDA_Activated;
int PIDA_Testresault;
int PIDA_Testsollwert;
int PIDA_Testistwert;
int p_factorA, i_factorA , d_factorA;
int errorA;
int sumirterfehlerA;
int maximalfehlerA;
int maximalfehelersummeA;
int maximalausschlagA;
int i_maximalausschlagA;
int p_maximalausschlagA;
int i_resultatA;
int p_resultatA;
int d_resultatA;
int lezterFunktionswertA;

//Funktionen PIDA
void initPID(int maximalausschlag_,int p_factor_,int i_factor_,int d_factor_);
int pidA(int sollwert,int istwert);


//Werte für PIDA

int PIDB_Activated;
int PIDB_Testresault;
int PIDB_Testsollwert;
int PIDB_Testistwert;
int p_factorB, i_factorB , d_factorB;
int errorB;
int sumirterfehlerB;
int maximalfehlerB;
int maximalfehelersummeB;
int maximalausschlagB;
int i_maximalausschlagB;
int p_maximalausschlagB;
int i_resultatB;
int p_resultatB;
int d_resultatB;
int lezterFunktionswertB;






#endif /* PID_A_H_ */
