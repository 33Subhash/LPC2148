#include<LPC214X.h>
#include"header.h"

//Led on P0.15 
#define LED 1<<15 

extern int flag ;

int main(){
	ext_int_init();
	
	IODIR0|=LED; //Setting LED pin as OUTPUT 
	
	
	while(1){
		if (flag ==1 ){
			IOSET0=LED;
			delay_ms(200);
			IOCLR0=LED ;
			delay_ms(200);
		}
		
	}
	
}
