#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8, TextLCD::LCD16x2); // rs, e, d4-d7 ojo rw=gnd

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

//Variables Globales
char men_in[16];

// Prototipos de las funciones 
void rx_serie(void);

// Hilos 
Thread hilo_serie;

// main() runs in its own thread in the OS
int main()
{
lcd.locate(0,0);                // columna 0 fila 1 (renglón Uno)
lcd.printf("Hola buen dia ;)");  // Imprimir una cadena de texto
ThisThread::sleep_for(3000ms);  // Espera de 3 segundos
lcd.cls();                      // Borrar LCD

hilo_serie.start(rx_serie);

    while (true) {

    }
}


void rx_serie(void)
{
    while(true)
    {
        if (serial_port.readable())
            {
            char men_in[16]={0}; 
            serial_port.read(men_in,15);
            lcd.locate(0,0);                // columna 0 fila 1 (renglón Uno)
            lcd.printf(" Dato Recibido :");
            lcd.locate(0,1);                // columna 1 fila 2 (renglón Uno)
            lcd.printf("%s",men_in);
            }    
        else
            {
            serial_port.write("..Esperando..\n\r",15);
            lcd.cls();
            lcd.printf("..Esperando...:(");  // Imprimir una cadena de texto
            }
        ThisThread::sleep_for(2000ms); 
        } 
}