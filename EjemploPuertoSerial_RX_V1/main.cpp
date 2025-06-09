#include "mbed.h"

// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

//static BufferedSerial serial_port(USBTX, USBRX);
BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

DigitalOut miled (PA_5); //LED1=D13=PA_5
BusOut puertoLed(PB_3,PB_5,PB_4,PB_10);//D3,D4,D5,D6

Thread hilo_rx_serie;

void rx_serie(void);

//char men_out[21];
char men_in[9];

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
        for(int i=0; i<10;i++)
            {
            men_in[i]  = NULL;
            } 

        if (serial_port.readable())
        {
          serial_port.read(men_in,9); //recibo 9 caracteres
        if(!strcmp(men_in,"adelante"))  //compara cadena de texto recibida con "adelante"
            {
            puertoLed =0b1100; 
            serial_port.write("escribio adelante\n\r",19);
            }
        else if(!strcmp (men_in ,"atras" ))  
            {
            puertoLed =0b0011;
            serial_port.write("escribio atras\n\r",16);
            }
        else if(!strcmp (men_in ,"izquierda" ))  
            {
            puertoLed =0b1001;
            serial_port.write("escribio izquierda\n\r",20);
            }
        else if(!strcmp (men_in ,"derecha" ))  
            {
            puertoLed =0b0110;
            serial_port.write("escribio derecha\n\r",18);
            }
        else
            {
            serial_port.write("Error\n\r",7); 
            puertoLed =0b1010;  
            }
        } 
        ThisThread::sleep_for(1000ms);
    }
}
/* //copiar y/o encadenar cadenas de texto
//strcpy(men_out,men_in);
//strcat(men_out,"\n\r");
//serial_port.write(men_out, sizeof(men_out));
//serial_port.sync(); // flush de buffer serial
*/