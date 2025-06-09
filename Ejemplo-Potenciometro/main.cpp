#include "mbed.h"

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

AnalogIn pinMedido(PA_0); //PA_0=A0

float datoMedido;
char mensaje[40]={0};
int dato_Entero;
int dato_decimal;

//Prototipo de función
void medirAnalogo(void);
void Decimal_Entero(float decimal);

//Hilos
Thread hilo_medirAnalogo;

int main()
{
serial_port.write("Hola.!  Arranque del programa.\n\r",32);
hilo_medirAnalogo.start(medirAnalogo);
    while (true) {
           
      }
}

//Función medir Pin Analogo
void medirAnalogo(void)
{
    int datoADC;

    while (true) 
    {
    datoMedido=(pinMedido.read()*3.3); // lectura del voltaje como flotante entre 0.0 y 1.0
    datoADC=pinMedido.read_u16();// lectura del voltaje como entero corto sin signo entre 0x0 y 0xFFFF
    sprintf(mensaje,"ADC: %d\n\r",datoADC);
    serial_port.write(mensaje,sizeof(mensaje));
    Decimal_Entero(datoMedido);
    sprintf(mensaje,"Vol: %d.%d V\n\r",dato_Entero,dato_decimal);
    serial_port.write(mensaje,sizeof(mensaje));
    ThisThread::sleep_for(1500ms);
    }
}

//funcion decimal entero
void Decimal_Entero(float decimal){
    dato_Entero=int(decimal);
    dato_decimal=(decimal-int(decimal))*1000;
}