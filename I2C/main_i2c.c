#include<LPC214X.h>
#include"header.h"

#define EEPROM 0xA0 
#define I2CWRITE 0X00
#define I2CREAD 0X01 

int main(){
	u8 data=0xff;
	
	
	uart_init(9600);
	
	///BYTE Write Frame 
	
	I2C_Init(); // Intialization of I2C 
	I2C_Start(); //Sending start condition on the I2C bus 
	I2C_Write(EEPROM|I2CWRITE); //Sending slave address 
	I2C_Write(0x13);	//Address of higher bytes 
	I2C_Write(0x49);	//Address of lower bytes 
	I2C_Write(data);	//Writing data to location 
	I2C_STOP(); //Genarate stop condition to realese I2C bus  
	
/*
BYTE READ FRAME 
*/
	
	///BYTE dummy write  Frame 
	I2C_Start(); //Sending start condition on the I2C bus 
	I2C_Write(EEPROM|I2CWRITE); //Sending slave address 
	I2C_Write(0x13);// Address of higher bytes 
	I2C_Write(0x49); //Address of lower bytes 

	///Re-start and BYTE Write frame 
	I2C_Start(); //Sending start condition on the I2C bus 
	I2C_Write(EEPROM|I2CREAD); //Sending slave address 
	data=I2C_READ_NACK();  //Data recived from slave 
	I2C_STOP(); //Genarate stop condition to realese I2C bus  	
	
	uart_tx_string("recived data from EEPROM :");
	uart_tx_int(data);
	
}
