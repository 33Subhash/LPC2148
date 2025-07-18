#include<LPC214X.h>
int flag=0 ;

/// Interrupt Service Routine-ISR 

__irq void Ext_ISR(void) 
{
	flag^=1;
	EXTINT|=1;
	VICVectAddr=0; //End of interrupt execution 
}


///external interrupt intialization function 

void ext_int_init(void){
	
	
	EXTMODE|=1 ; //Edge trigging mode for EXT1
	EXTPOLAR&=~(1); //Active low triggered 
	PINSEL0|=0XC; //Configuring pin function as EXT0
	
	/* initialize the interrupt vector */
  
	VICIntSelect &= ~ (1<<14);            // EINT2 selected as IRQ 16
  VICVectAddr0 = (unsigned int)Ext_ISR; // address of the ISR
  VICVectCntl0 = (1<<5) | 14;            // 
  VICIntEnable = (1<<14);               // EINT2 interrupt enabled

}	
