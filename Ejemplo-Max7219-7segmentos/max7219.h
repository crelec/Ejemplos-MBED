#ifndef MAX7219_H
#define MAX7219_H

#include "mbed.h"

class Max7219 {
public:
    Max7219(PinName mosi, PinName sclk, PinName cs); // Constructor con pines específicos
    void init();            // Inicializar el display
    void send(const char* data); // Enviar una cadena de datos al display
    void clear();           // Limpiar el display
    void setIntensity(uint8_t level); // Ajustar la intensidad del display (0-15)
    void setScanLimit(uint8_t digits); // Configurar el límite de dígitos visibles (1-8)
    void displayTest(bool enable); // Activar o desactivar el modo de prueba del display

private:
    SPI spi;                // Interfaz SPI para comunicación con el MAX7219
    DigitalOut cs;          // Pin de Chip Select
    void writeRegister(uint8_t reg, uint8_t data); // Escribir en un registro del MAX7219
};

#endif // MAX7219_H