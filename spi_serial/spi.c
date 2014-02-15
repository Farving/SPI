/** INCLUDES ************************************************************************************/
#include <xc.h>

#include <stdio.h>
#include <stdbool.h>       // Includes true/false definition

#include "config.h"
#include "spi.h"
/** GLOBALS **************************************************************************************/
unsigned char SPI_Mode;
unsigned char SPI_Master;

/** Functions ************************************************************************************/
void SPI_Init(unsigned char Master, unsigned char Mode)
{
	printf("Initializing SPI... ");
	SPI_Mode = Mode;
	SPI_Master = Master;
	if (Master)
	{
		SPI_MOSI_Tris = 0;	// Output
		SPI_MISO_Tris = 1;	// Input
		if (Mode == 0b00)	// SCLK Idle low
		{
			SPI_SCLK_MASTER = 0;
           //         LATAbits.LATA2 = 0;
		} else if (Mode == 0b11) {	// SCLK Idle High
			SPI_SCLK_MASTER = 1;
		}
		SPI_SCLK_Tris = 0; 	// Output
                TRISAbits.TRISA2 = 0;
	} else {
		SPI_MOSI_Tris = 1;	// Input
		SPI_MISO_Tris = 0;	// Output
		SPI_SCLK_Tris = 1;	// Input
	}

	printf("Done\r\n");
}


void SPI_Delay(unsigned int count)
{
	while(--count)
		;
}

unsigned char SPI_Rx()
{
	unsigned char i, data = 0;
	for (i=0; i<8; i++)
	{
		data <<= 1;
		if (SPI_Mode == 0b00)
		{
			if (SPI_Master)
			{
				SPI_SCLK_MASTER = 0;
				SPI_Delay(SPI_Clock);
				SPI_SCLK_MASTER = 1;
                                //SPI_Delay(SPI_Clock);
				if (SPI_MISO_Rx)
					data |= 1;
			} else {
				while(!SPI_SCLK_SLAVE);
				if (SPI_MOSI_Rx)
					data |= 1;
			}
		}
	}
	return data;
}

void SPI_Tx(unsigned char data)
{
	unsigned char i;
	for (i=8; i>0; i--)
	{
		if (SPI_Mode == 0b00)
		{
			if (SPI_Master)
			{
				SPI_SCLK_MASTER = 0;
				if (data & 0x80)
					SPI_MOSI_Tx = 1;
				else
					SPI_MOSI_Tx = 0;
				SPI_Delay(SPI_Clock);
				SPI_SCLK_MASTER = 1;
			} else {
				while(SPI_SCLK_SLAVE);
				if (data & 0x80)
					SPI_MISO_Tx = 1;
				else
					SPI_MISO_Tx = 0;
			}
		}

		data <<= 1;
	}
}


unsigned char SPI_RxTx(unsigned char data)
{
	return data;
}