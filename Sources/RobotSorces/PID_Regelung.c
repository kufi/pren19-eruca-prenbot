/*
 * PID.c
 *
 *  Created on: Dec 14, 2012
 *      Author: 8460p
 */
#include "MKL25Z4.h"
#include "PID.h"



void initPID(int maximalausschlag_,int p_factor_,int i_factor_,int d_factor_){
	p_factorA=p_factor_;
	i_factorA=i_factor_;
	d_factorA=d_factor_;
	maximalausschlagA=maximalausschlag_;
	maximalfehlerA=1000;
	p_maximalausschlagA=1000;
	sumirterfehlerA =0;
	maximalfehelersummeA=500;
	i_maximalausschlagA =500;
	lezterFunktionswertA=0;
	i_resultatA=0;
	
	p_factorB=p_factor_;
    i_factorB=i_factor_;
    d_factorB=d_factor_;
	maximalausschlagB=maximalausschlag_;
	maximalfehlerB=1000;
	p_maximalausschlagB=1000;
	sumirterfehlerB =0;
	maximalfehelersummeB=500;
	i_maximalausschlagB =500;
	lezterFunktionswertB=0;
	i_resultatB=0;
}

int pidA(int sollwert,int istwert){
	int temp;
	int ret;
	
	errorA = sollwert - istwert;
	
	//Calculate Pterm and limit error overflow
	if (errorA > maximalfehlerA){
	    p_resultatA = p_maximalausschlagA;
	  }
	  else if (errorA < -maximalfehlerA){
	    p_resultatA = -p_maximalausschlagA;
	  }
	  else{
	    p_resultatA = p_factorA * errorA;
	  }
	
	// Calculate Iterm and limit integral runaway
	  temp = sumirterfehlerA + errorA;
	  if(temp > maximalfehelersummeA){
		 i_resultatA = i_maximalausschlagA;
		 sumirterfehlerA = i_maximalausschlagA;
	  }
	  else if(temp < -maximalfehelersummeA){
	    i_resultatA = -i_maximalausschlagA;
	    sumirterfehlerA = -i_maximalausschlagA;
	  }
	  else{
		  sumirterfehlerA = temp;
	      i_resultatA = i_factorA * temp;
	  }
	  // Calculate Dterm
	    d_resultatA = d_factorA * (lezterFunktionswertA - istwert);

	    lezterFunktionswertA = istwert;

	    ret = p_resultatA+i_resultatA+d_resultatA;
	    
	    if(ret > maximalausschlagA){
	      ret = maximalausschlagA;
	    }
	    else if(ret < -maximalausschlagA){
	      ret = -maximalausschlagA;
	    }
	    return (ret)/10;
	 
}

int pidB(int sollwert,int istwert){
	int temp;
	int ret;
	
	errorB = sollwert - istwert;
	
	//Calculate Pterm and limit error overflow
	if (errorB > maximalfehlerB){
	    p_resultatB = p_maximalausschlagB;
	  }
	  else if (errorB < -maximalfehlerB){
	    p_resultatB = -p_maximalausschlagB;
	  }
	  else{
	    p_resultatB = p_factorB * errorB;
	  }
	
	// Calculate Iterm and limit integral runaway
	  temp = sumirterfehlerB + errorB;
	  if(temp > maximalfehelersummeB){
		 i_resultatB = i_maximalausschlagB;
		 sumirterfehlerB = i_maximalausschlagB;
	  }
	  else if(temp < -maximalfehelersummeB){
	    i_resultatB = -i_maximalausschlagB;
	    sumirterfehlerB = -i_maximalausschlagB;
	  }
	  else{
		  sumirterfehlerB = temp;
	      i_resultatB = i_factorB * temp;
	  }
	  // Calculate Dterm
	    d_resultatB = d_factorB * (lezterFunktionswertB - istwert);

	    lezterFunktionswertB = istwert;

	    ret = p_resultatB+i_resultatB+d_resultatB;
	    
	    if(ret > maximalausschlagB){
	      ret = maximalausschlagB;
	    }
	    else if(ret < -maximalausschlagB){
	      ret = -maximalausschlagB;
	    }
	    return (ret)/10;
}

