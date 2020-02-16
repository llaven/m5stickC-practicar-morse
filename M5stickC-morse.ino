/*
 * Entrenador morse para M5StickC
 * Por: Emilio Ruiz www.emilio.com.mx
 * Basado en morse.pde de Eric Ayars
 * 
 */

/*
 * Instalación del Buzzer activo:
 * 
 *  Cable negro a GND
 *  Cable rojo a GO26
 *  
 */

#include <M5StickC.h>
#define OUTLINE 26
#define DOTLENGTH 50   // All timing is based on this time. Lower for faster code.
int letraAleatoria;
char segmento[]= "kmrsuaa";
char message[] = "";
char letra;
bool apagador;


void dot() {
    // Make a dot signal
    digitalWrite(OUTLINE, HIGH);
    delay(DOTLENGTH);
    digitalWrite(OUTLINE, LOW);
    delay(DOTLENGTH); 
}

void dash() {
    // Make a dash signal
    digitalWrite(OUTLINE, HIGH);
    delay(3*DOTLENGTH);
    digitalWrite(OUTLINE, LOW);
    delay(DOTLENGTH);
}

void letterBreak() {
    // The break between letters is 3x(dot length).
    // One dot length comes automatically at the end of
    // the previous dot or dash, so 2 more are needed.
    delay(2*DOTLENGTH);
}

void wordBreak() {
    // The break between words is 4x(dot length).
    // Three come for free since a letter just ended,
    // so 4 more are needed.
    delay(4*DOTLENGTH);
}

void send(char letter) {
    // Sends the given letter to the output
    switch (letter) {
        case 'A': 
        case 'a': dot(); dash(); break;
        case 'B':
        case 'b': dash(); dot(); dot(); dot(); break;
        case 'C':
        case 'c': dash(); dot(); dash(); dot(); break;
        case 'D':
        case 'd': dash(); dot(); dot(); break;
        case 'E':
        case 'e': dot(); break;
        case 'F':
        case 'f': dot(); dot(); dash(); dot(); break;
        case 'G':
        case 'g': dash(); dash(); dot(); break;
        case 'H':
        case 'h': dot(); dot(); dot(); dot(); break;
        case 'I':
        case 'i': dot(); dot(); break;
        case 'J':
        case 'j': dot(); dash(); dash(); dash(); break;
        case 'K':
        case 'k': dash(); dot(); dash(); break;
        case 'L':
        case 'l': dot(); dash(); dot(); dot(); break;
        case 'M':
        case 'm': dash(); dash(); break;
        case 'N':
        case 'n': dash(); dot(); break;
        case 'O':
        case 'o': dash(); dash(); dash(); break;
        case 'P':
        case 'p': dot(); dash(); dash(); dot(); break;
        case 'Q':
        case 'q': dash(); dash(); dot(); dash(); break;
        case 'R':
        case 'r': dot(); dash(); dot(); break;
        case 'S':
        case 's': dot(); dot(); dot(); break;
        case 'T':
        case 't': dash(); break;
        case 'U':
        case 'u': dot(); dot(); dash(); break;
        case 'V':
        case 'v': dot(); dot(); dot(); dash(); break;
        case 'W':
        case 'w': dot(); dash(); dash(); break;
        case 'X':
        case 'x': dash(); dot(); dot(); dash(); break;
        case 'Y':
        case 'y': dash(); dot(); dash(); dash(); break;
        case 'Z':
        case 'z': dash(); dash(); dot(); dot(); break;
        case '0': dash(); dash(); dash(); dash(); dash(); break;
        case '1': dot(); dash(); dash(); dash(); dash(); break;
        case '2': dot(); dot(); dash(); dash(); dash(); break;
        case '3': dot(); dot(); dot(); dash(); dash(); break;
        case '4': dot(); dot(); dot(); dot(); dash(); break;
        case '5': dot(); dot(); dot(); dot(); dot(); break;
        case '6': dash(); dot(); dot(); dot(); dot(); break;
        case '7': dash(); dash(); dot(); dot(); dot(); break;
        case '8': dash(); dash(); dash(); dot(); dot(); break;
        case '9': dash(); dash(); dash(); dash(); dot(); break;
        case ',': dash(); dash(); dot(); dot(); dash(); dash(); break;
        case '.': dot(); dash(); dot(); dash(); dot(); dash(); break;
        case '?': dot(); dot(); dash(); dash(); dot(); dot(); break;
        case ';': dash(); dot(); dash(); dot(); dash(); dot(); break;
        case '\'': dash(); dash(); dash(); dot(); dot(); dot(); break;
        case '-': dash(); dot(); dot(); dot(); dot(); dash(); break;
        case '/': dash(); dot(); dot(); dash(); dot(); break;
        case '(': 
        case ')': dash(); dot(); dash(); dash(); dot(); dash(); break;
        case '_': dot(); dot(); dash(); dash(); dot(); dash(); break;
        case ' ': wordBreak(); break;
    }
    letterBreak();
}

void setup() {
    M5.begin();
    M5.Lcd.setRotation(3);
    M5.Lcd.fillScreen(BLACK);
    M5.Axp.ScreenBreath(0);
    
    pinMode(OUTLINE, OUTPUT);
    digitalWrite(OUTLINE, LOW);
    
    randomSeed(analogRead(0));
    delay(1000);
    // Say Hi on power up
    char message[] = "HI";
    for (byte j=0; j<sizeof(message); j++) {    
        send(message[j]); // Send each character in the message.
    }
    
    bool apagador = false;

}

char mensaje(){
  letraAleatoria=random(0,7);
  letra = segmento[letraAleatoria];
  return letra;
}

void loop() {
    M5.update(); 

    if (M5.BtnA.wasPressed()){
      apagador = !apagador;
    }

    // Enviar mensaje al buzzer
    if (apagador){
      M5.Axp.ScreenBreath(255);
      M5.Lcd.setCursor(40,20);
      M5.Lcd.setTextSize(1);
      M5.Lcd.print("(( TX Morse ))");
      delay(1000);
      M5.Lcd.setTextSize(2);
      M5.Lcd.setCursor(10,40);
      M5.Lcd.print("Preparado");
      delay(1000);
      M5.Lcd.setCursor(10,40);
      M5.Lcd.print("Preparado.");
      delay(1000);
      M5.Lcd.setCursor(10,40);      
      M5.Lcd.print("Preparado..");
      delay(1000);
      M5.Lcd.setCursor(10,40);
      M5.Lcd.print("Preparado...");
      delay(1000);
      M5.Axp.ScreenBreath(0);
      M5.Lcd.fillScreen(BLACK);


      char message[] = {mensaje(), mensaje(), mensaje(), mensaje(), mensaje(), mensaje(), '\0'};
      delay(1000);    // three second delay before (and between).
  
      for (byte j=0; j<sizeof(message); j++) { 
        send(message[j]); // Send each character in the message.
      }

      delay(4000);

      for (byte j=0; j<sizeof(message); j++) { 
        send(message[j]); // Send each character in the message.
      }

      delay(4000);

      for (byte j=0; j<sizeof(message); j++) { 
        send(message[j]); // Send each character in the message.
      }


      delay(2000);

      M5.Axp.ScreenBreath(255);
      M5.Lcd.setCursor(10,23);
      M5.Lcd.setTextSize(4);


      for (byte j=0; j<sizeof(message); j++) { 
        delay(300);
        M5.Lcd.print(message[j]); // Enviar los caracteres al display
      }

     delay(4000);

     M5.Lcd.setCursor(7,60);
     M5.Lcd.setTextSize(1);
     M5.Lcd.print("Boton M5 para detener");
     delay(1000);
     M5.Lcd.fillScreen(BLACK);
     M5.Axp.ScreenBreath(0);

    }

  delay(1000);
}
