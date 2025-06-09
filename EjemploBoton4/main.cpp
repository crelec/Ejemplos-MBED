#include "mbed.h"

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);

//Defino pines
DigitalIn mi_sw0(PC_13); //Boton Tarjeta
DigitalOut mi_led0(PA_5); //Led Tarjeta PA_5=D13

// main() runs in its own thread in the OS
int main()
{
 serial_port.write("Hola.!  Arranque del programa.\n\r",32);
    
    while (true) {
        if(mi_sw0==1)
            {
                serial_port.write("No pulsado\n\r",12);
                mi_led0=0;
            }
        else
            {
                serial_port.write("Pulsado   \n\r",12);
                mi_led0=1;
            }
    ThisThread::sleep_for(250ms);
    }
}