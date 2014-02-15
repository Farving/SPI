#ifndef MCP4921_H
#define	MCP4921_H
/** DEFINES ************************************************************************************/
/** INTERNAL ************************************************************************************/
#define MCP4921_CS    		LATBbits.LATB10		// RB10 pin 21
#define MCP4921_CS_Tris		TRISBbits.TRISB10
	
/** EXTERNAL ************************************************************************************/


/** Prototypes ************************************************************************************/
unsigned char MCP4921_Device_Connection_Test();

unsigned char MCP4921_Initialize();

void MCP4921_Set_Vout(unsigned int data);

#endif	/* MCP4921_H */