# Presentación de mensajes por puerto serial


## Introducción 

Este programa muestra el estado de un botón de dos formas: a través de un led y a partir de un mensaje mostrado por puerto serial. El ejemplo hace uso 
del botón integrado de la tarjeta (PC_13) el cual es normalmente abierto y también del led integrado de la tarjeta (PA_5). Adicionalmente se utilizan los pines 
PA_2 y PA_3 para la transmisión y recepción de datos.


## Visualización de datos

Dado que Keil Studio en línea no tiene habilitado la opción de visualizar por terminal, es neceserio utilizar otra aplicación que nos permita visualizar los datos
seriales. Para ello existen dos alternativas que cumplen con esta tarea: Putty y Tera term.

### Putty 

[Link de descarga](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html "Redireccionar a pagina oficial Putty").

Cuando se abre la aplicación se observa es lo siguiente:

![puttyPanel](https://user-images.githubusercontent.com/59096507/210011350-6df879b1-9425-4508-9801-10e67481054d.png)

Se debe seleccionar la opción **Serial**, escribir el **COM** en donde está instalada la tarjeta (ver en Administrador de dispositivos de Windows) y
finalmente configurar la velocidad que lo usual es de 9600. Luego de la configuración simplemente seleccionamos "open" y ya se podría observar los datos seriales.

Putty inicialmente está configurado para enviar el caracter de la tecla que presionemos inmediatamente. Para enviar un texto o varios caracteres en conjunto
se deben activar las siguientes opciones:

![PuttyForceOn](https://user-images.githubusercontent.com/59096507/210012675-00c70c26-41af-4a9f-8544-0d3001f7f32b.png)

### Tera Term

[Link de descarga](https://ttssh2.osdn.jp/index.html.en "Redireccionar a pagina oficial Tera Term").

Cuando se abre la aplicación se observa es lo siguiente:

![TeraPanel](https://user-images.githubusercontent.com/59096507/210012229-581efcdc-993d-4546-b84a-3afc3efc7372.png)

Se selecciona la opción **Serial** y luego simplemente se busca en el menú desplegable el **COM** asociado a la tarjeta y se presiona "OK". Las demás configuraciones se establecen en el propio terminal.
Una de las problemáticas a la hora de usar Tera Term es que no es posible configurar para enviar texto y solamente está la opción de recibir el caracter asociado
a la tecla que se presione.



