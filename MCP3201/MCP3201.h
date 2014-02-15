#ifndef MCP3201_H
#define	MCP3201_H
/** DEFINES ************************************************************************************/
/** INTERNAL ************************************************************************************/
#define MCP3201_CS    		LATBbits.LATB11		// RB11 pin 22
#define MCP3201_CS_Tris		TRISBbits.TRISB11

/** EXTERNAL ************************************************************************************/


/** Prototypes ************************************************************************************/
unsigned char MCP3201_Device_Connection_Test();

unsigned char MCP3201_Initialize();

unsigned int MCP3201_Read_Conversion();

#endif	/* MCP3201_H */