#include "mbed.h"

#define tiempo_refresco        2
#define tiempo_conteo        500

char deco_dato[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};// digitos HEXA
char sol[4];

//Definiciones de pines.
BusOut mi_anodos(PC_7,PB_6,PA_7,PA_6); //D9,D10,D11,D12
BusOut mi_Segmentos(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9);  //D2,D3,D4,D5,D6,D7,D8

// Prototipos de las funciones 
void visualiza(void);
void rutinabcd(int numero);

// Hilos 
Thread Hilo_visualizar;

// main() runs in its own thread in the OS
int main()
{
    Hilo_visualizar.start(visualiza);
    int contador=0;

        while (true) {
    rutinabcd(contador);
    contador++;
    thread_sleep_for(tiempo_conteo);
    }
}


void rutinabcd(int numero)
{
    sol[0]=0,sol[1]=0,sol[2]=0,sol[3]=0;
    int coci=10;
    char res=0;
    char cont=0;
    while(coci !=0)
    {
        res =(numero%10);
        coci =numero/10;
        sol[cont]=res;
        numero=coci;
        cont ++;
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
