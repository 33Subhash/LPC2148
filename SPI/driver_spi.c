#include<LPC214X.h>
#include"header.h"

#define CS 1<<7 
#define SPI_FLAG (S0SPSR&0X80) 

void SPI_Master_Init(void )
{
	PINSEL0 = PINSEL0 | 0x00001500; /* Select P0.4, P0.5, P0.6, P0.7 as SCK0, MISO0, MOSI0 and GPIO */
	S0SPCR = 0x0020; /* SPI Master mode, 8-bit data, SPI0 mode */
	S0SPCCR = 0x10; /* Even number, minimum value 8, pre scalar for SPI Clock */
}

u8 SPI_Master_write(char data){

	IO0CLR=CS ; //To select slave 
	S0SPDR=data; //Assinging to transfer 
	
	while( SPI_FLAG == 0); //Wait till transmission  compeleted 
	data=S0SPDR; //Assigning data from slave  
	
	IO0CLR=CS; //To disselect slave 
}

u8 SPI_Master_Read(void ){
	int data=0 ;
	IO0CLR=CS ; //To select slave 
	
	S0SPDR=data; //Assinging to transfer 
	
	while( SPI_FLAG == 0); //Wait till transmission  compeleted 
	data=S0SPDR; //Assigning data from slave  
	
	IO0CLR=CS; //To disselect slave
	return data ;
}

