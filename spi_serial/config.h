#ifndef SPI_CONFIG_H
#define	SPI_CONFIG_H

/** Microchip PIC24 ************************************************************************************/
#define SPI_SCLK_Tris	TRISBbits.TRISB15	// RB15 pin 26
#define SPI_SCLK_MASTER	LATBbits.LATB15
#define SPI_SCLK_SLAVE	PORTBbits.RB15

#define SPI_MOSI_Tris	TRISBbits.TRISB14	// RB14 pin 25
#define SPI_MOSI_Tx		LATBbits.LATB14
#define SPI_MOSI_Rx		PORTBbits.RB14

#define SPI_MISO_Tris	TRISBbits.TRISB4	// RB4 pin 11
#define SPI_MISO_Tx		LATBbits.LATB4
#define SPI_MISO_Rx		PORTBbits.RB4

#define SPI_SPEED 		100 					// 100kHz
#define SPI_MULTIPLIER 	1
#define SPI_Clock 		(100/SPI_SPEED)*SPI_MULTIPLIER

#endif	/* SPI_CONFIG_H */

