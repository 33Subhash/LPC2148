#include<LPC214X.h>
#include "header.h"

#define SI (I2C0CONSET & 0x08) 

/* Intialization of i2c to communicate */

void I2C_Init(void)
{
	PINSEL0 = PINSEL0 | 0x00000050; // Configure P0.2 and P0.3 as SCL0 and SDA0 respectively
	I2C0CONSET = 0x40; // Enable I2C  //
	I2C0SCLL = 0x32; //I2C data rate 300Khz  //
	I2C0SCLH = 0x32; // I2C data rate 300Khz  //
}

/*Genarate start condition to start i2c bus */

void I2C_Start(void)
{
	I2C0CONSET = 0x20; /* Set Start bit for Start condition */
	while ( SI == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x28; /* Clear Start bit and SI bit */
}


/*Writing data on I2C bus */

void I2C_Write( u8 data )
{
	I2C0DAT = data; /* Load data to be written into the data register */
	I2C0CONSET = 0x40; /* Enable I2C */
	while( SI == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x08;  /* Clear SI bit */
}


/*Reading data on I2C  bus */ 

unsigned char I2C_READ_NACK( void )
{
	I2C0CONSET = 0x40; /* Enable I2C without Acknowledge */
	while( (I2C0CONSET & 0x08) == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x08;   /* Clear SI bit */
	return I2C0DAT; /* Return received data */
}


/*Genarate stop condition */

void I2C_STOP( void )
{
	I2C0CONSET = 0x50; /* Set Stop bit for Stop condition */
}
