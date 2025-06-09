#include "mbed.h"

#define tiempo_refresco        2

//Definiciones de pines.
BusOut mi_anodos(PA_6,PA_7,PB_6,PC_7); //D12,D11,D10,D9
BusOut mi_Segmentos(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8,PA_9);  //D2,D3,D4,D5,D6,D7,D8
BusIn datoIn(PA_0,PA_1); //A0,A1

char respuesta;
char msg[4][4];

// Prototipos de las funciones 
void visualiza(void);

// Hilos 
Thread Hilo_visualizar;

int main()
{
    /*Mensaje vacio*/
    msg[3][0] = 0b11111111;
    msg[3][1] = 0b11111111;
    msg[3][2] = 0b11111111;
    msg[3][3] = 0b11111111;
    /*Mensaje PAUS*/
    msg[1][0] = 0b00001100;
    msg[1][1] = 0b00001000;
    msg[1][2] = 0b01000001;
    msg[1][3] = 0b00010010;
    /*Mensaje PLAY*/
    msg[2][0] = 0b00001100;
    msg[2][1] = 0b01000111;
    msg[2][2] = 0b00001000;
    msg[2][3] = 0b00010001;
    /*Mensaje __FF*/
    msg[0][0] = 0b11111111;
    msg[0][1] = 0b11111111;
    msg[0][2] = 0b00001110;
    msg[0][3] = 0b00001110;

Hilo_visualizar.start(visualiza);

    while (true) {
    respuesta=datoIn;
    }
}

//Funcion Visualización
void visualiza(void)
{
    char estado=0;
    while(true)
    {
        switch (estado)
        {
        case 0:
        mi_anodos = 0b1110; 
        mi_Segmentos = msg[respuesta][0];
        break;
        
        case 1:  
        mi_anodos=0b1111;
        break;

        case 2:
        mi_anodos = 0b1101; 
        mi_Segmentos = msg[respuesta][1];
        break;
        
        case 3:  
        mi_anodos=0b1111;
        break;

        case 4:
        mi_anodos = 0b1011; 
        mi_Segmentos = msg[respuesta][2];
        break;
        
        case 5:  
        mi_anodos=0b1111;
        break;

        case 6:
        mi_anodos = 0b0111; 
        mi_Segmentos = msg[respuesta][3];
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