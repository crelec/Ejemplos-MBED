#include "mbed.h"

//Defino pines del bus de entrada
BusIn mi_datoin(PA_0,PA_1,PA_4,PB_0); //A0,A1,A2,A3
BusOut mi_Segmentos(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9,PC_7); //D2,D3,D4,D5,D6,D7,D8

char deco_dato[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0x08,0x03,0x46,0x21,0x06,0x0e};// digitos HEXA

// main() runs in its own thread in the OS
int main()
{
char indice=0;

    while (true) {
    mi_Segmentos=deco_dato[indice];
    
        if(indice==15)
            {
                indice=0;
            }
        else
            {
                indice++;
            }
    ThisThread::sleep_for(500ms);
    }
}

 /* // Binario Hexadecimal
    //Entrada sw-> salida Display    
    mi_Segmentos=deco_dato[mi_datoin];
 */

/*  //Contador digitos Hexadecimales
    mi_Segmentos=deco_dato[indice];
    
    if(indice==15)
      {
        indice=0;
      }
    else
       {
        indice++;
       }
    ThisThread::sleep_for(500ms);*/  