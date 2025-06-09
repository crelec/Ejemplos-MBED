#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

DigitalOut miled (PA_5); //LED1=D13=PA_5
BusOut puertoLed(PB_3,PB_5,PB_4,PB_10);//D3,D4,D5,D6

Thread hilo_rx_serie;

void rx_serie(void);

char men_in[2];

// main() runs in its own thread in the OS
int main()
{
    hilo_rx_serie.start(rx_serie);
    serial_port.write("Arranque programa.\n\r",21);

    while (true) {
    miled=!miled;
    ThisThread::sleep_for(BLINKING_RATE);
    }
}

void rx_serie(void)
{
    while(true)
    {
        if (serial_port.readable())
        {
            serial_port.read(men_in,1);
            if (men_in[0]=='a') {
            serial_port.write("Digito a\n\r",10);
            puertoLed=0b0011;
            }
            else if (men_in[0]=='s') {
            serial_port.write("Digito s\n\r",10);
            puertoLed=0b1100;
            }
            else{
                serial_port.write("..Error..\n\r",11);
                puertoLed=0b1010;
            }
        } 
        ThisThread::sleep_for(50ms);      
    }
}