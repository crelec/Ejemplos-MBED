#include "mbed.h"

#define tiempo_conteo                                   300
#define tiempo_parpadeo                                 100
#define tiempo_refresco                                 3

//Variables Globales 
char U=0;
char D=0;
char C=0;
char UM=0;
char deco_dato[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10,0x08,0x03,0x46,0x21,0x06,0x0e};// digitos HEXA

//Definiciones pines
BusOut mi_anodos(PC_7,PB_6,PA_7,PA_6); //D9,D10,D11,D12
BusOut mi_Segmentos(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9);  //D2,D3,D4,D5,D6,D7,D8
DigitalOut led(PA_5);

// Prototipos de las funciones 
void visualiza(void);
void cuenta(void);
 
// Hilos 
Thread Hilo_visualizar;
Thread Hilo_contar;

// main() runs in its own thread in the OS
int main()
{
    Hilo_visualizar.start(visualiza);
    Hilo_contar.start(cuenta);
    led = 0;

    while (true) {
        led=!led;
        thread_sleep_for(tiempo_parpadeo);
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
        mi_Segmentos = deco_dato[U]; 
        break;  

        case 1:  
        mi_anodos=0b1111;
        break;

        case 2:  
        mi_anodos=0b1101;
        mi_Segmentos = deco_dato[D];
        break;

        case 3:  
        mi_anodos=0b1111;
        break;

        case 4:  
        mi_anodos=0b1011;
        mi_Segmentos = deco_dato[C];
        break;

        case 5:  
        mi_anodos=0b1111;
        break;

        case 6:  
        mi_anodos=0b0111;
        mi_Segmentos = deco_dato[UM];
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

void cuenta(void)
{
    while(true)
    {
        U++;
        if (U==10)
        {
            U=0;
            D++;
            if (D==10) 
                {
                D=0;
                C++;
                if(C==10)
                  {
                      C=0;
                      UM++;
                  }
                }
        }
        thread_sleep_for(tiempo_conteo);
    }
} 