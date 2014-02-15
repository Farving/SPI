#ifndef SPI_H
#define	SPI_H
/** DEFINES ************************************************************************************/
/** EXTERNAL ************************************************************************************/
#define SPI_MASTER 		1
#define SPI_SLAVE		0

#define SPI_MODE_00		0b00
#define SPI_MODE_01		0b01
#define SPI_MODE_10		0b10
#define SPI_MODE_11		0b11

/** Prototypes ************************************************************************************/
void SPI_Init(unsigned char Master, unsigned char Mode);

void SPI_Delay(unsigned int count);

unsigned char SPI_Rx();
void SPI_Tx(unsigned char data);
unsigned char SPI_RxTx(unsigned char data);

#endif	/* SPI_H */

