#include "mbed.h"
#include <chrono>

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
char mensaje[40]={0};

Timer tiempoUno;

long  long dato_ms,dato_us,dato_s;

int main()
{
    serial_port.write("---...!---\n\r",12);
    tiempoUno.start();
    ThisThread::sleep_for(10ms); //wait_us(1000);
    tiempoUno.stop();
    
    //Lectura de tiempo en segundos
    dato_s = chrono::duration_cast<chrono::seconds>(tiempoUno.elapsed_time()).count();
    sprintf(mensaje,"Tiempo %llu s\n\r",dato_s);
    serial_port.write(mensaje,sizeof(mensaje));
    
    //Lectura de tiempo en milisegundos
    dato_ms = chrono::duration_cast<chrono::milliseconds>(tiempoUno.elapsed_time()).count();
    sprintf(mensaje,"Tiempo %llu ms\n\r",dato_ms);
    serial_port.write(mensaje,sizeof(mensaje));

    //Lectura de tiempo en microsegundos
    dato_us = tiempoUno.elapsed_time().count();
    sprintf(mensaje,"Tiempo %llu us\n\r",dato_us);
    serial_port.write(mensaje,sizeof(mensaje));
}