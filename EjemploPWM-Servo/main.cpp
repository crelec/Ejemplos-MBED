#include "mbed.h"

// main() runs in its own thread in the OS
DigitalOut miled(D13);

PwmOut Pinsalida(D6);

int angulo=510; //cero grados 0.5ms

Thread hilo_servo;

void servomotor(void);

int main()
{
    hilo_servo.start(servomotor);
    while (true) {
        miled=!miled;
        ThisThread::sleep_for(500ms);
    }
}

void servomotor(void){

Pinsalida.period_ms(20); //Establece el periodo PWM en milisefundos (int)
Pinsalida.pulsewidth_us(angulo);//Establece el ancho de pulso PWM en microsegundos (int)
ThisThread::sleep_for(1000ms);
    while (true) {
        if(angulo>2210){ //2.2 ms para 180 grados.
            ThisThread::sleep_for(1000ms);
            angulo=510;
            Pinsalida.pulsewidth_us(angulo);
            ThisThread::sleep_for(1000ms);
        }
        else{
            Pinsalida.pulsewidth_us(angulo);
            angulo +=100;
            ThisThread::sleep_for(100ms);
        }
    }
}