#include "mbed.h"

#define tiempo_tarea      1000ms
#define BLINKING_RATE     500ms


// Prototipos de las funciones 
void Hilo_Tarea1 (void);
void Hilo_Tarea2 (void);

// Variables Pines
DigitalOut led(PA_5);
//Thread Tarea1(osPriorityNormal, OS_STACK_SIZE, nullptr, nullptr); //prioridad 1
//Thread Tarea2(osPriorityNormal, OS_STACK_SIZE, nullptr, nullptr);

Thread Tarea1; 
Thread Tarea2;

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
char mensaje[17];

int main()
{
    serial_port.write("Arranque del programa.\n\r",24);
       
    Tarea1.start(Hilo_Tarea1);
    Tarea2.start(Hilo_Tarea2);


    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

void Hilo_Tarea1(void)
{
const char Men_Tarea1[17] = "Tarea 1 Corre.\n\r";

    while(true)
    {
        sprintf(mensaje,Men_Tarea1);//formatear una cadena de caracteres
        serial_port.write(mensaje,sizeof(mensaje));
        //for (int i=0;i<1e6; i++) {wait_us(1);}
        ThisThread::sleep_for(tiempo_tarea);
    }
}

void Hilo_Tarea2(void)
{
const char Men_Tarea2[17] = "Tarea 2 Corre.\n\r";

    while(true)
    {
        sprintf(mensaje,Men_Tarea2);//formatear una cadena de caracteres
        serial_port.write(mensaje,sizeof(mensaje));
        //for (int i=0;i<1e6; i++) {wait_us(1);}
        ThisThread::sleep_for(tiempo_tarea);
    }
}