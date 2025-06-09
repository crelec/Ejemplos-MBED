# EjemploBoton2 Leer un Botón simple para mostra el problema de los rebotes en entradas mecanicas.

## Introducción 
Este programa muestra el problema de los rebotes en entradas mecánicas tipo botón. 
El ejemplo usa el botón propio de la tarjeta Núcleo 401RE (PC_13) el cual tiene un rebote bajo ya que posee un circuito hardware RC diseñado para tal fin. 
Si usamos otro Pin del micro en este caso uso el pin PB_3 se observa con facilidad el problema en mención. Para la observaciòn del rebote se puede utilizar un osciloscopio o leds para el ejemplo usamos los pines D2,D4,D5,D6 para la visualizaciòn del rebote.

![Captura de pantalla de 2022-11-07 05-36-53](https://user-images.githubusercontent.com/111470363/200290289-428feb4c-c8a3-45c1-a075-4c801955fed3.png)

## Montaje
Para este montaje se utilizó cuatro leds y un botón conectados de la siguiente manera:

![EjemploBoton2_bb](https://user-images.githubusercontent.com/59096507/209984804-c7651021-b936-44f5-92ca-cf549e2b7b2d.png)

## Visualización de rebotes en osciloscopio
Si el botón a utilizar se implementa el ejemplo sin usar ningún tipo de eliminador de rebotes, ya sea de forma física o por programación se logrará ver un señal de salida de este tipo:

![rebote_osciloscopio](https://user-images.githubusercontent.com/59096507/206878869-f6ef529d-ac06-46eb-a859-3020cb27851b.jpg)

La cantidad de rebotes que se logren visualizar será totalmente dependiente del tipo de botón que se utilice, es importante considerar que cada botón es diferente físicamente por lo tanto la eliminación de rebotes para cada botón también lo será.

Debido a que la tarjeta está programada para contar cada vez que se detecte un flanco de subida, entonces cada vez que se pulse el botón se contará el pulso y adicional los rebotes que tiene el botón como se vió en la imagen anterior, por lo que finalmente la cuenta del programa dependerá más de la cantidad de rebotes que tiene el botón que de la pulsación realizada por el usuario.


