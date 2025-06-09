# Ejemplo Uso BusIn, BusOut y escritura en el puerto Serial.

## Introducción
El siguiente programa muestra el uso de BusIn Y BusOut como una alternativa a la hora de trabajar con multiples pines de la tarjeta, para esto se utiliza un primer 
ejemplo aplicativo que consiste en mostrar un dato de tipo caracter en puerto serial y tambien la representación en binario por leds a partir del BusOut. El segundo 
ejemplo aplicativo consiste en utilizar el BusIn para recibir un dato de tipo binario y realizar la representación en leds a partir del BusOut de ese número,
adicionalmente se mostró ese dato de entrada en decimal a partir de puerto serial.



## Montaje

Para controlar el dato de entrada se utilizó un Dip Switch de ocho posiciones, y para mostrar la salida se hizo uso de un arreglo de 8 leds.

![datosBusDipSwitch_bb](https://user-images.githubusercontent.com/59096507/211005425-7a3898b0-9bac-4c78-bfac-748ef360691e.svg)


## sprintf()

`sprintf` es una función que se utiliza para formatear una cadena de texto. En este caso, se está utilizando para crear una cadena de texto que contiene el valor de `dato` seguido de un salto de línea `\n` y un retorno de carro `\r`. La cadena de texto resultante se almacena en la variable `mensaje`. Es importante tener en cuenta el espeficador de formato `%c` que nos proporciona el tipo de dato a visualizar por serial que en este caso la letra `c` indica dato de tipo caracter.

Los especificadores de formato se pueden apreciar [aqui](https://learn.microsoft.com/es-es/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170#type-field-characters "Especificador de formato").


## Método write()
Es el que envía los datos a visualizar por serial, recibe como parámetros el dato y la cantidad de bytes(tamaño del dato) que se desee visualizar. En este caso, 
se incializó el puerto serial a partir de crear el objeto con el nombre `serial_port` y se usó el método `write()` para enviar la cadena de caracteres `mensaje` de la siguiente forma: `serial_port.write(mensaje, sizeof(mensaje))`. La función `sizeof()` retorna la cantidad de bytes de la estructura de datos de la variable enviada por parámetro.

Para el primer ejemplo de visualización por serial, el dato contiene el valor de 64, pero debido a que se hace uso del especificador de formato char `%c` 
el dato que se visualiza en puerto serial es `@`, debido a que es el caracter correspondiente a ese valor numérico.

Para visualizar que valor numérico es correspondiente a cada caracter, revisar la tabla ASCII, dar clic [aquí](https://elcodigoascii.com.ar/ "ASCII")
