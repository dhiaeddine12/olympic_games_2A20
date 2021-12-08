
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Definition des variables
int tempPin = 0;  // Broche A0
float valBrute;   // Valeur brute sur A0
float valTemp;    // Temperature


LiquidCrystal_I2C lcd(0x27,16,2);  // LCD1602 I2C 0x27 

void setup()
{
  lcd.init();   // Initialisation du LCD 
 }
void loop()
{ 
  // Mesure la tension sur la broche A0
  float valBrute = analogRead(tempPin);
  // Calcul de la température en degré Celcius
  float valTemp = valBrute * (5.0/1023.0 *100.0);


  // Affichage sur LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temperature : ");
  lcd.setCursor(1,1);
  lcd.print(valTemp);
  lcd.setCursor(6,1);
  lcd.print(" Celcius");
  delay(1000);
}
