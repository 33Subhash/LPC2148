#include<LPC214X.h>
#include "header.h"

#define START (1<<24)
#define DONE ((AD1GDR>>31)&1)
#define CH_NUM (1) 

void  adc_init(void ){
	PINSEL0|=0x3000; //Configure pin as ADC1.7   
	AD1CR|=(4<<8); //Produce clock for adc <4.5MHZ 
 	AD1CR|=1<<21 ; //Enable Operational mode  
}


u32 adc_read(void ){
	
	u32 data ;
	AD1CR|=CH_NUM; //Selecting ADC channel 
	AD1CR|=START; //Starting conversion  
	while(DONE == 0); //Waiting till conversion done   
	
	AD1CR^=START ; //Stoping conversion 
	AD1CR^=CH_NUM ; //Diselecting ADC channel
	
	data=((AD1GDR>>6)&0x3FF); //Reading data from ADC1.7
	return data ;
}

