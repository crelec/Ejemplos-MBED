#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
DigitalOut myled1(PA_10); //D2
DigitalOut myled2(PB_5); //D4
DigitalOut myled3(PB_4); //D5
DigitalOut myled4(PB_10); //D6

DigitalIn myBoton(PC_13); //PC_13 Boton tarjeta ó pin PB_3=D3

//myBoton.mode(PullUp); //Usar con PB_3=D3 Si uso PC_13 sobra

int contador=0;
int anterior_boton=1;
int nuevo_boton;
    
    while(1) {
        nuevo_boton = myBoton;
        if ((nuevo_boton==0) && (anterior_boton==1)) contador++;
        myled4 = contador & 0x01;
        myled3 = (contador & 0x02)>>1;
        myled2 = (contador & 0x04)>>2;
        myled1 = (contador & 0x08)>>3;
        anterior_boton = nuevo_boton; 
    }
}

