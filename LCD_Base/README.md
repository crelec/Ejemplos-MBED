Para el uso de la **LCD HD44780** se utilizó el drive disponible en el **cookbook de ARM** https://os.mbed.com/components/HD44780-Text-LCD/. La librería se importó de https://os.mbed.com/users/simon/code/TextLCD/.

Para el ejemplo se utiliza **Mbed OS 6.15.1** del drive disponible en el cookbook se copian los archivos **TextLCD.cpp** y **TexLCD.h** como archivos nuevos **NO** se importa la librería TextLCD.h. Se debe buscar todas las líneas que usan la función **wait()**; y se de debe reemplazar por **ThisThread::sleep_for();** 
Para tiempos de espera en el orden de los milisegundos y **wait_us();** para tiempos de espera del orden de los micro segundos.

**Ejemplo.**

ThisThread::sleep_for(15ms); //wait(0.015);  
wait_us(1640); //wait(0.00164);

La justificación del cambio en la función wait() se encuentra en: https://os.mbed.com/docs/mbed-os/v6.15/apis/wait.html
* **Circuito Eléctrico**
![nucleo-LCD_bb](https://user-images.githubusercontent.com/111470363/209947989-b2cc87be-4667-4007-b38a-b688d4a7fffc.jpg)
