#include<LPC214X.h> 
#include "header.h"

#define LED 1<<15 



int main()
{
	char display_string1[20]="welcome to lcd" ;
	char display_string2[10]="ARM7";
	
		
	lcd_init();
	int i;
	for (i=0;display_string1[i] ;i++){
		lcd_data(display_string1[i]);
	}
	
	lcd_cmd(0xc6);
	for (i=0;display_string2[i] ;i++){
		lcd_data(display_string2[i]);
	}
	
	while(1);
	
}

