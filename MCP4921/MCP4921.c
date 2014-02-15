/** INCLUDES ************************************************************************************/
#include <xc.h>

#include <stdio.h>
#include <stdbool.h>       // Includes true/false definition

#include "../Includes/bb_spi/bb_spi.h"
#include "MCP4921.h"

/** Functions ************************************************************************************/
unsigned char MCP4921_Device_Connection_Test()
{
	//I2C_Start();
	//return I2C_Tx(MCP3221_ADDR << 1 | I2C_WRITE);
	return 1;
}

unsigned char MCP4921_Initialize()
{
	SPI_Init(SPI_MASTER, SPI_MODE_00);
	MCP4921_CS_Tris = 0;

	return MCP4921_Device_Connection_Test();
}

void MCP4921_Set_Vout(unsigned int data)
{
	MCP4921_CS = 0;
	SPI_Tx((data >> 8) | 0x70);
	SPI_Tx(data);
	MCP4921_CS = 1;
}