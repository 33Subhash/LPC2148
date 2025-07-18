#include "header.h"
#include <lpc214X.h>

#define LED 1<<15 

int main(){
	IO0DIR=LED;
	IO0SET=LED;
	delay_ms(200);
	IO0CLR=LED;
	delay_ms(200);
}
