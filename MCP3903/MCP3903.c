/** INCLUDES ************************************************************************************/
#include <xc.h>

#include <stdio.h>
#include <stdbool.h>       // Includes true/false definition

#include "../spi_serial/spi.h"
#include "MCP3903.h"

/** Functions ************************************************************************************/
unsigned char MCP3903_Device_Connection_Test()
{
	//I2C_Start();
	//return I2C_Tx(MCP3221_ADDR << 1 | I2C_WRITE);
	return 1;
}

unsigned char MCP3903_Initialize()
{
	SPI_Init(SPI_MASTER, SPI_MODE_00);
    MCP3903_CS = 1;
    //LATBbits.LATB5 = 1;
	MCP3903_CS_Tris = 0;
    //TRISBbits.TRISB5 = 0;
    //TRISBbits.TRISB5 = 0;
    TRISAbits.TRISA0 = 0;

	return MCP3903_Device_Connection_Test();
}

unsigned int MCP3903_Read_Conversion()
{
	unsigned int data = 0;

	MCP3903_CS = 0;
    //LATBbits.LATB5 = 0;
    LATAbits.LATA0 = 0;
	//data = (SPI_Rx() & 0x1F) << 7;
	//data |= (SPI_Rx() >> 1);
    unsigned int data0, data1, data2, data3, data4;
    data0 = 0; data1 = 0; data2 = 0; data3 = 0; data4 = 0;
//    unsigned int data1 = 0;
    data0 = SPI_Rx();
    data1 =  data0 & 0x1F;
    data2 = data1 << 7;
//    unsigned int data2 = 0;
    data3 = SPI_Rx();
    data4 = data3 >> 1;
    data = data2 | data4;

    asm("NOP");
	MCP3903_CS = 1;
    //LATBbits.LATB5 = 1;
    LATAbits.LATA0 = 1;

    return data;
}