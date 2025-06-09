#include "mbed.h"

PwmOut Pinsalida(D6); //Pin de salida PWM

// main() runs in its own thread in the OS
int main()
{
Pinsalida.period_ms(20); //Establece el periodo PWM en milisefundos (int)

    while (true) {
        for(int i=0;i<19;i++){
            Pinsalida.pulsewidth_ms(i); //Establece el ancho de pulso PWM en milisegundos (int)
            ThisThread::sleep_for(1000ms);
        }
    }
}