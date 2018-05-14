/* =============================================================
 *  Programa desenvolvido durante o Arduino Day Santos 2018
 * =============================================================
 * Autores: Thiago Ferauche e Gil Oliveira
 * (Santos Hacker Clube)
 * 
 * Sketch que realiza o sorteio de um número após pressionar um pushbutton,
 * usando o ruído da entrada analógica de um Arduino Uno, e a saída é 
 * realizada pelo porta Serial e também por um Display LCD 
 * (Grove-LCD RGB Backlight)
 * 
  * 
 */

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 90;
const int colorB = 0;
long randNumber;
int bot = 0;
int val_max = 24;

void setup() {
   Serial.begin(9600);
   // if analog input pin 0 is unconnected, random analog
   // noise will cause the call to randomSeed() to generate
   // different seed numbers each time the sketch runs.
   // randomSeed() will then shuffle the random function.
   randomSeed(analogRead(0));
   pinMode(3,INPUT); 
   Serial.println("ARDUINO DAY Santos 2018 - Sorteio (SHC)");
   Serial.println("Aguardando pressionar botão....");
   // set up the LCD's number of columns and rows:
    lcd.begin(0,1);

    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Pressione Botao...");

}

void loop() {
   // print a random number from 0 to 299
   bot = digitalRead(3);
   if(bot == 0 ) {
       lcd.begin(0,1);
       lcd.setRGB(colorR, colorG, colorB);
       lcd.print("Sorteando...");
      for(int i=0; i<10;i++) {
          Serial.print(".");
          delay(300);
      }
      Serial.println();
      Serial.println("E o grande vencedor é ");
      
      randNumber = random(1, val_max);// print a random number from 10 to 19
      lcd.begin(0,1);
      lcd.setRGB(colorR, colorG, colorB);
      Serial.print(randNumber);
      lcd.print(randNumber);
   }  
      
}
