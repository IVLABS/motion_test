#include "serialUSB.h"
using namespace LibSerial;

serialUSB::serialUSB(const char* const SERIAL_PORT_DEVICE,int baudrate)
  {
 
	serial_port.Open( SERIAL_PORT_DEVICE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not open serial port " 
                  << SERIAL_PORT_DEVICE 
                  << std::endl ;
        exit(1) ;
    }
     //
    // Set the baud rate of the serial port.
    //
    serial_port.SetBaudRate( SerialStreamBuf::BAUD_115200 ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the baud rate." << std::endl ;
        exit(1) ;
    }
    //
    // Set the number of data bits.
    //
    serial_port.SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the character size." << std::endl ;
        exit(1) ;
    }
    //
    // Disable parity.
    //
    serial_port.SetParity( SerialStreamBuf::PARITY_NONE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not disable the parity." << std::endl ;
        exit(1) ;
    }
    //
    // Set the number of stop bits.
    //
    serial_port.SetNumOfStopBits( 1 ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not set the number of stop bits."
                  << std::endl ;
        exit(1) ;
    }
    //
    // Turn on hardware flow control.
    //
    serial_port.SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
    if ( ! serial_port.good() ) 
    {
        std::cerr << "Error: Could not use hardware flow control."
                  << std::endl ;
        exit(1) ;
    }  
  }
void serialUSB::sendData(int* s,int array_length)
  {
	

	char a;
	char* b;

	for (int i=0; i<array_length;i++)
	{  
	a=s[i];
	b=&a;
	b=const_cast<char *>(b);
    serial_port.write(b,1);
    
}
   }

