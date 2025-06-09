#include "mbed.h"

#define tiempo_refresco        2

char deco_dato[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0x3f,0x06};// digitos HEXA
char sol[4];

//Definiciones de pines.
BusOut mi_anodos(PC_7,PB_6,PA_7,PA_6); //D9,D10,D11,D12
BusOut mi_Segmentos(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9);  //D2,D3,D4,D5,D6,D7,D8

//static BufferedSerial serial_port(USBTX, USBRX);
static BufferedSerial serial_port(PA_2, PA_3);
//static BufferedSerial serial_port(PA_9, PA_10); //PA_10=D2=UART1_RX  PA_9=D8=UART1_TX "Uso bluetooth"

// Prototipos de las funciones 
void visualiza(void);
void rx_serie(void);

// Hilos 
Thread Hilo_visualizar;
Thread hilo_serie;

char men_in[5];
char mensaje[20]={0};

// main() runs in its own thread in the OS
int main()
{
    Hilo_visualizar.start(visualiza);
    hilo_serie.start(rx_serie);

        while (true) {
    
    }
}

//Función Visualización
void visualiza(void)
{
    char estado=0;
    
    while(true)
    {
    switch  (estado)
        { 
        case 0:  
        mi_anodos=0b1110; 
        mi_Segmentos = deco_dato[sol[0]]; 
        break;  

        case 1:  
        mi_anodos=0b1111;
        break;

        case 2:  
        mi_anodos=0b1101;
        mi_Segmentos = deco_dato[sol[1]];
        break;

        case 3:  
        mi_anodos=0b1111;
        break;

        case 4:  
        mi_anodos=0b1011;
        mi_Segmentos = deco_dato[sol[2]];
        break;

        case 5:  
        mi_anodos=0b1111;
        break;

        case 6:  
        mi_anodos=0b0111;
        mi_Segmentos = deco_dato[sol[3]];
        break;

        default: 
        mi_anodos=0b1111;
        break;
        }
        estado++; 
        if (estado==7) 
            estado = 0;
        thread_sleep_for(tiempo_refresco);
        }
}

void rx_serie(void)
{
    int numeroEntero;

    while(true)
    {
        if (serial_port.readable())
            {
            char mensaje[20]={0};
            char men_in[5]={0}; 
            serial_port.read(men_in,5);
            if(((men_in[3]-48)>=0 && (men_in[3]-48)<=9) && ((men_in[2]-48)>=0 && (men_in[2]-48)<=9) && ((men_in[1]-48)>=0 && (men_in[1]-48)<=9) && ((men_in[0]-48)>=0 && (men_in[0]-48)<=9))
                {
                serial_port.write("..Valido..\n\r",12);
                sol[0]=men_in[3]-48;
                sol[1]=men_in[2]-48;
                sol[2]=men_in[1]-48;
                sol[3]=men_in[0]-48;
                }
            else
                {   
                serial_port.write("..In Valido..\n\r",15);
                sol[0]=11;
                sol[1]=11;
                sol[2]=11;
                sol[3]=11;
                }
            }    
        else
            {
            serial_port.write("..Esperando..\n\r",15);
            sol[0]=10;
            sol[1]=10;
            sol[2]=10;
            sol[3]=10;
            }
        ThisThread::sleep_for(500ms); 
        } 
}