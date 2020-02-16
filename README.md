# m5stickC-practicar-morse
Programa para M5stickC y practicar código morse, reutilicé el código de Eric Ayars morse.pde que originalmente es para utilizarlo en un Attiny. Por el momento el código envía una serie de caracteres (KMRSUA) de forma aleatoria al concluir el envío aparece en pantalla los caracteres para comprobar su tu copia (recepción) del código morse fue la correcta.


![M5StickC practica morse](https://www.emilio.com.mx/imagenes/m5stickc-morse-01.jpg)

## Buzzer activo
Debido a que el M5StickC no tiene una función de "tone" como en arduino, entonces utilizo un buzzer activo para instalalo debes conseguir además del buzzer activo una resistencia de 1 kilo ohm la conexión es la siguiente:

* Cable negro o negativo del buzzer al pin GND
* Cable rojo o positivo del buzzer a la resistencia
* El otro extremo de la resistencia al pin G26

![M5StickC practica morse resistencia](https://www.emilio.com.mx/imagenes/m5stickc-morse-02.jpg)
![M5StickC practica morse resistencia](https://www.emilio.com.mx/imagenes/m5stickc-morse-03.jpg)


## Mejoras
Posteriormente activaré el otro botón del M5StickC para agregar otro juego de caracteres y continuar avanzando en el conocimiento de todas las letras del alfabeto en código Morse.

## Aprender morse
El secreto, como en todo aprendizaje de cualquier tema, es la disciplina en la práctica, realizar 30 minutos diarios hará que avances rápidamente en el aprendizaje del código morse. 

Otro secreto super importante es que no aprendas el código morse pensando en puntos y rayas, sino en sonido, aprende los sonidos nunca los "puntos y rayas" ya que si lo hace así tendrás que realizar un doble proceso mental: convertir el sonido a puntos y rayas y buscar mentalmente el caracter que corresponde a esos puntos y rayas. Así que ve directo sobre el sonido, cada letra en el código morse suena distinto.

![Código morse](https://www.emilio.com.mx/diy/aprende-morse.png)



