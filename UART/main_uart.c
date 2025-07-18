#include<LPC214X.h> 
#include"header.h"

int main(){
	uart_init(9600);
	while(1){
		uart_tx_string("intialized uart0");
		uart_tx_string("\n\r");
		delay_ms(100);
	}
	
}
