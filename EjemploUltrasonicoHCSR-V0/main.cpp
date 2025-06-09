#include "mbed.h"

#define Tiempo_Medida 500ms

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);

//Defino Pines
DigitalOut Trg(PA_10); //D2
DigitalIn Echo(PB_3);//D3

char mensaje[40]={0};
long long distancia_cm;

Timer tiempo1;

Thread hilo_DisparoEntrada(osPriorityNormal, OS_STACK_SIZE,nullptr, nullptr);

void DisparoEntrada();

int main()
{
    serial_port.write("Hola.! Arranque del programa.\n\r",31);
    Trg=0;
    hilo_DisparoEntrada.start(DisparoEntrada);
    
    while (true) {

    }
}

void DisparoEntrada(void)
{
    while(true)
    {
        Trg=1;
        wait_us(10);
        Trg=0;
        while(!Echo){};
        tiempo1.reset();
        tiempo1.start();
        while(Echo){};
        distancia_cm=((tiempo1.elapsed_time().count())/58);
        sprintf(mensaje,"La distancia es: %llu \n\r", distancia_cm); 
        serial_port.write(mensaje, sizeof(mensaje));
        ThisThread::sleep_for(Tiempo_Medida);
    }
 }