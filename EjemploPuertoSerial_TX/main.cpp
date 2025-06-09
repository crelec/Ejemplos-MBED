#include "mbed.h"

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"
char mensaje[40]={0};

// main() runs in its own thread in the OS
int main()
{
int i=0;
serial_port.write("Hola.! Arranque del programa.\n\r",31);

    while (true) {
        if(i < 10){
            sprintf(mensaje,"contador %d\n\r",i);
            serial_port.write(mensaje,sizeof(mensaje));
            i++;
        }
        else {
        i=0;
        }
        ThisThread::sleep_for(500ms);
    }
}

