#include "max7219.h"
#include <cstdio>

Max7219::Max7219(PinName mosi, PinName sclk, PinName cs_pin) : spi(mosi, NC, sclk), cs(cs_pin) {
    cs = 1; // Inicializar el pin CS en alto
}

void Max7219::init() {
    spi.format(8, 3);       // Configuración del SPI: 8 bits, modo 3
    spi.frequency(1000000); // Frecuencia de 1 MHz para el SPI
    
    setScanLimit(7);        // Mostrar los 8 dígitos
    writeRegister(0x09, 0xFF); // Activar modo de decodificación BCD para todos los dígitos
    setIntensity(2);        // Ajuste de intensidad a un nivel bajo
    writeRegister(0x0C, 0x01); // Activar el modo normal (salir de apagado)
    clear();                // Limpiar la pantalla al iniciar
}

void Max7219::send(const char* data) {
    int length = strlen(data); // Obtener la longitud de la cadena
    for (int i = 0; i < length; i++) {
        cs = 0;                             // Seleccionar el dispositivo
        spi.write(length-i);       // Seleccionar el dígito adecuado (de izquierda a derecha) 
        spi.write(data[i] - '0');            // Convertir el carácter a número
        cs = 1;                             // Deseleccionar el dispositivo
    }
}

void Max7219::clear() {
    for (int i = 1; i <= 8; i++) {
        writeRegister(i, 0x0F); // Enviar "espacio en blanco" a todos los dígitos
    }
}

void Max7219::setIntensity(uint8_t level) {
    if (level > 15) level = 15; // Limitar el nivel de intensidad a 15
    writeRegister(0x0A, level); // Escribir en el registro de intensidad
}

void Max7219::setScanLimit(uint8_t digits) {
    if (digits > 7) digits = 7; // Limitar el número de dígitos a 8 (0 a 7)
    writeRegister(0x0B, digits); // Configurar el límite de escaneo
}

void Max7219::displayTest(bool enable) {
    writeRegister(0x0F, enable ? 0x01 : 0x00); // Activar o desactivar el modo de prueba
}

void Max7219::writeRegister(uint8_t reg, uint8_t data) {
    cs = 0;               // Seleccionar el dispositivo
    spi.write(reg);       // Escribir el registro
    spi.write(data);      // Escribir el dato
    cs = 1;               // Deseleccionar el dispositivo
}