#include "Raspberry_I2C.h"
#include "PID.h"
#include "EasyRider.h"
#include "cstdlib"

extern RaspberryPtr raspberryDataPtr;


void remotecontroll(byte *buffer){
	char command;
	int parameter;
	
	
	if(raspberryDataPtr.received){
		command= (char) *buffer ;
		parameter= (*(buffer+1) << 8) + *(buffer+1);
		
		
		switch(command)
			 {
			    case 't':
			    	regelverzoegerung=parameter;
			    break;

			    case 'p':
			    	p_factorA=parameter;
			    break;
			    case 'i':
			    	i_factorA=parameter;
			    break;
			    case 'd':
			    	d_factorA=parameter;
			    break;
			    case 'm':
			    	maximalausschlagA=parameter;
			    
			 }
		
			
		
	}
	
	
	
}

