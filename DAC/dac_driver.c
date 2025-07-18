#include"header.h"
#include<LPC214X.h>

void dac_init(void ){
	PINSEL1|=0X00004;
}

void dac_write(u32 digital_data){
	DACR =((digital_data&0x3ff)<<6 );  
}

