#include "mbed.h"

// main() runs in its own thread in the OS
int main()
{
DigitalOut myled(PA_5); //PA_5=D13
DigitalIn myBoton(PC_13); //PC_13 Boton tarjeta ó pin PB_3=D3
//myBoton.mode(PullUp); //Usar con PB_3 si usa PC_13 sobra
  
    while (true) {
        myled = myBoton;
    }

}