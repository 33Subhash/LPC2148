#include<LPC214X.H>
#include"header.h"
#define FACTOR 10.23 

int main(){
	u32 data=0 ;
	dac_init();
	
	///Genarate SAWTOOTH wave 
	while(1){
		dac_write(data); //Writting digital data to genarate analog output 
		delay_us(200);//delay to produce samples
		data+=FACTOR; 
		
		if(data > 1023 ){
			data=0;
		}
	}
}
