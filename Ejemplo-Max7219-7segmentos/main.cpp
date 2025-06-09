#include "mbed.h"
#include "max7219.h"

// Define los pines para MOSI, SCLK y CS según tu configuración de hardware
Max7219 m(PB_5, PB_3, PA_8); // PB_5 = MOSI, PB_3 = SCLK, PA_8 = CS

int main() {
    m.init(); // Inicializar el display
    
    while (true) {
       
        m.clear();          // Limpiar el display
        m.send("7");        // Mostrar el número "7"
        ThisThread::sleep_for(1000ms); // Esperar 1 segundo
        
        m.clear();
        m.send("123456");   // Mostrar el número "123456"
        ThisThread::sleep_for(1000ms);
        
        m.clear();
        m.send("10");       // Mostrar el número "10"
        ThisThread::sleep_for(1000ms);
        
        m.clear();
        m.send("98765432"); // Mostrar el número "98765432"
        ThisThread::sleep_for(1000ms);
    }
}

/* Testeo modulo
m.displayTest(1);
ThisThread::sleep_for(1000ms);
m.displayTest(0);
ThisThread::sleep_for(1000ms);
*/