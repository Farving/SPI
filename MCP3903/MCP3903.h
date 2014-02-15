#ifndef MCP3903_H
#define	MCP3903_H
/** DEFINES ************************************************************************************/
/** INTERNAL ************************************************************************************/
#define MCP3903_CS    		LATBbits.LATB11		// RB11 pin 22
#define MCP3903_CS_Tris		TRISBbits.TRISB11

/** EXTERNAL ************************************************************************************/


/** Prototypes ************************************************************************************/
unsigned char MCP3903_Device_Connection_Test();

unsigned char MCP3903_Initialize();

unsigned int MCP3903_Read_Conversion();

#endif	/* MCP3903_H */