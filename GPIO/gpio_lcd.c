#include<LPC214x.h>
#include "header.h"

#define RS 1<<16
#define RW 1<<17 
#define EN 1<<18 

void delay(){
	int i=0;
	for(i=0;i<2000000 ;i++);
}

void lcd_cmd(unsigned int cmd ){
	IOCLR1=RS; //Pull down the register select pin for command 
	IOCLR1=RW; //pull down the readwrite  pin to down to write  
	
	IOCLR1=0xff000000;//Clearing all data bits  
	IOSET1=(cmd & 0xFF) << 24 ; //Setting command number to data pins   
	
	
	//Enabling lcd to read cmd 
	IOSET1=EN;
	delay();
	IOCLR1=EN ;

}



void lcd_data(unsigned char data ){
	IOSET1=RS; //Pull up the register select pin for data
	IOCLR1=RW; //pull down the readwrite  pin to down to write  
	
	IOCLR1=0xff000000;//Clearing all data bits  
	IOSET1= (data & 0xFF) << 24 ; //Setting command number to data pins   
	
	
	//Enabling lcd to read cmd 
	IOSET1=EN;
	delay();
	IOCLR1=EN ;

}



void lcd_init(void) {
    IODIR1 |= (RS | RW | EN | 0xFF000000); // Set control and data pins as output

    lcd_cmd(0x38); // Function Set: 8-bit, 2 lines, 5x7 dots
    delay();

    lcd_cmd(0x0E); // Display ON, cursor ON
    delay();

    lcd_cmd(0x06); // Entry mode: increment cursor
    delay();

    lcd_cmd(0x01); // Clear display
    delay();

    lcd_cmd(0x83); // Cursor position (row 1, column 4)
    delay();
}

