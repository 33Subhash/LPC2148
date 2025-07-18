#include<LPC214X.h>
#include "header.h"


int main(){
	int adc_data;
	adc_init();
	uart_init(9600);
	
	while(1){
		adc_data=adc_read();
		uart_tx_string("ADC output : ");
		uart_tx_int(adc_data);
		uart_tx_string("\r\n");
		delay_ms(1000);
	}
	
}
