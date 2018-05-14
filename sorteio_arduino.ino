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
   // set up do LCD
    lcd.begin(0,1);
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("Pressione Botao...");

}

void loop() {
   /// captura a entrada do botão
   /// 0 - botão pressionado
   /// 1 - botão não pressionado
   bot = digitalRead(3); 
   if(bot == 0 ) {
       /// setup up do LCD
       /// Aqui o código pode ser melhorado para não ter que inicializar o LCD
       /// toda a vez que vou exibir algo nele
       lcd.begin(0,1);
       lcd.setRGB(colorR, colorG, colorB);
       lcd.print("Sorteando...");
       /// for para causar suspense :D
       for(int i=0; i<10;i++) {
          Serial.print(".");
          delay(300);
       }
       
       Serial.println();
       Serial.println("E o grande vencedor é ");

       //Gera o número aleatório na faixa estipulado de 1 a val_max
       randNumber = random(1, val_max);// print a random number from 10 to 19
       lcd.begin(0,1);
       lcd.setRGB(colorR, colorG, colorB);
       Serial.print(randNumber);
       lcd.print(randNumber);
   }        
}
