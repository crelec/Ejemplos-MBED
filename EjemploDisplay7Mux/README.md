Contador libre 0 a 9999.

En este ejemplo uso el concepto de hilos **(Tarea periódica)** para su desarrollo. Los display en sus segmentos se enciende con ceros y se usan los pines del microcontrolador (D2,D3,D4,D5,D6,D7,D8) con la función de bus definido por el usuario **BusOut()**. El común de cada uno de los display con un cero se activa el display, para este ejemplo se usan cuatro display (cuatro comunes) que se agrupan en un bus definido por el usuario usando un total de cuatro pines del microcontrolador (D9,D10,D11,D12). **Nota:** Todo se está trabajando a 3.3V
