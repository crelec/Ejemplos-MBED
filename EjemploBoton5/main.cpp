#include "mbed.h"

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
char mensaje[40]={0};

//Defino pines del bus de entrada
BusIn mi_BusEntrada(PA_0,PA_1,PA_4,PB_0,PC_1,PC_0,PC_3,PC_2); //A0,A1,A2,A3,A4,A5,PC_3,PC_2
BusOut mi_BusSalida(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9,PC_7);//D2,D3,D4,D5,D6,D7,D8,D9

int main()
{
 serial_port.write("Hola.! Arranque del programa.\n\r",31);
 
 char dato=64;

while (true) {
    mi_BusSalida=dato;
    sprintf(mensaje,"%c\n\r",dato);
    serial_port.write(mensaje,sizeof(mensaje));
    dato++;
    ThisThread::sleep_for(500ms);
    }
}

/* Escribo en Pines del micro (BusOut) y en el puerto serial
dato=64; // ascii de @
mi_BusSalida=dato;
sprintf(mensaje,"%c\n\r",dato); //Imprimo como caracter %c
serial_port.write(mensaje,sizeof(mensaje));
dato++;
ThisThread::sleep_for(500ms);

*/
/* Leo Pines del micro (BusIn) y escribo en Pines del micro (BusOut) y en el puerto serial
dato=mi_BusEntrada;
mi_BusSalida=dato;
sprintf(mensaje,"%d\n\r",dato); //Imprimo como decimal sin signo %d
serial_port.write(mensaje,sizeof(mensaje));
ThisThread::sleep_for(500ms);
*/