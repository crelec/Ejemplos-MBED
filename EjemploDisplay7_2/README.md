# Display siete segmentos de cuatro dígitos: ejemplo Función para presentación de números en el rango 0 a  9999. 



## Introducción 

Este ejemplo  es un contador ascendente el cual a partir de un número entero en el rango de 0 a 9999 se descompone en unidades, decenas, centenas
y unidades de mil para verse reflejado en cada dígito del display a partir de visualización dinámica.

La dispoción de los pines para el display de cuatro dígitos es la siguiente:

![image](https://user-images.githubusercontent.com/59096507/213913645-95c29a7b-34e8-4877-ad79-083b90addf61.png)


## Codigo

El vector `deco_dato[]` contiene el arreglo de binarios de cómo se debe presentar el número en la posición en el cual está almacenado. Por ejemplo el primer
el primer elemento del vector tiene posición número 0, por lo cual en esa posición está almacenado el número binario para representar el cero en el display 
siete segmentos, el segundo elemento del vector tiene posición 1, por lo cual en esa posición está almacenado el número binario para representar el uno en el 
display y así sucesivamente.

El vector `sol[]` almacena los valores de unidades, decenas, centenas y unidades de mil del número a visualizar.

La función `void rutinabcd(int numero)` es la encargada de separar cada dígito del número enviado por parámetro y cada dígito se guarda en el vector `sol[]`.

El hilo `void visualiza(void)` se encarga de la visualización dinámica en el display, su funcionamiento es a partir de una máquina de estados utilizando un 
**switch case** el cual en cada caso se activa uno de los cuatro dígitos del display cada 4 milisegundos para visualizar el número correspondiente a ese dígito. 

                              
## Montaje

![sietesegTransistores2_bb](https://user-images.githubusercontent.com/59096507/213916037-91b58a28-3d67-4935-a517-53953a975c02.svg)

