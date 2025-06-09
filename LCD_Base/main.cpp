#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(PA_10,PB_3,PB_5,PB_4,PB_10,PA_8, TextLCD::LCD16x2); // rs, e, d4-d7 ojo rw=gnd

//Variables Globales
int dato_Entero;
int dato_decimal;

//funcion para conversión dato decimal a dato entero
void Decimal_Entero(float decimal){
    dato_Entero=int(decimal);
    dato_decimal=(decimal-int(decimal))*10; //1000
}

// main() runs in its own thread in the OS
int main()
{
lcd.locate(1,0);                // columna 1 fila 1 (renglón Uno)
lcd.printf("Buen dia Clase.");  // Imprimir una cadena de texto
lcd.locate(3,1);                // columna 3 fila 1 (renglón dos)
lcd.printf(".Unillanos.");      // Imprimir una cadena de texto
ThisThread::sleep_for(3000ms);  // Espera de 3 segundos
lcd.cls();                      // Borrar LCD
lcd.locate(7,0);                // columna 7 fila 1 (renglón Uno)
lcd.putc(123);                  //imprimir carácter ASCII 123 {
lcd.putc(125);                  //imprimir carácter ASCII 125 }
ThisThread::sleep_for(3000ms);  // Espera de 3 segundos
lcd.cls();                      // Borrar LCD

int contador=0;
float contadorf=0.0;
  
    while (true) {
        Decimal_Entero(contadorf);
        lcd.locate(0,0);
        lcd.printf("contador: %d.%d",dato_Entero,dato_decimal);
        contadorf=contadorf+0.1;
        ThisThread::sleep_for(500ms);
    }
}

//Impresión Variable Entera
/*
lcd.locate(0,0);
lcd.printf("Contador: %i",contador);
contador++;
ThisThread::sleep_for(200ms);
*/

//Impresion Variable Flotante
/*
Decimal_Entero(contadorf);
lcd.locate(0,0);
lcd.printf("contador: %d.%d",dato_Entero,dato_decimal);
contadorf=contadorf+0.1;
ThisThread::sleep_for(200ms);
*/