

#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#include <LiquidCrystal.h>
LiquidCrystal lcd(30, 36, 42, 48, 52, 51);

int GRUEN=7;
int GELB=5;
int ROT=6;




// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  lcd.begin(16, 2); //Im Setup wird angegeben, wie viele Zeichen und Zeilen verwendet werden. Hier: 16 Zeichen in 2 Zeilen.
 
  pinMode(GRUEN,OUTPUT);//Grüne LED  
  pinMode(GELB,OUTPUT);//Gelbe LED
  pinMode(ROT,OUTPUT);//Rote LED
  

  dht.begin();
}

void loop() {
 
  delay(2000);//Messintervall

 
  float h = dht.readHumidity();//Liest die Luftfeuchtigkeit aus und speichert sie in der Variable h ab 

  float t = dht.readTemperature();//Liest die Temperatur aus und speichert sie in der Variable t ab 

  

 
  // Checkt ob irgendwelche Fehler beim auslesen des Sensor gibt  und bricht das Programm früher ab  
  if (isnan(h) || isnan(t)) 
  {
    Serial.println("Fehler beim auslesen des Sensors!");
    return;
  }
  lcd.setCursor(0, 0); //Startposition der Darstellung auf dem LCD festlegen. lcd.setCursor(0,0) bedeutet: Erstes Zeichen in der ersten Zeile.
  lcd.print("Luftfeuchtigkeit:"); //Dort soll der Text „www.funduino.de“ erscheinen. Der Befehl lcd.setCursor ist dem Mikrocontrollerboard durch das Aufrufen der Bibliothek bekannt.
  lcd.setCursor(0, 1); // lcd.setCursor(0,1) bedeutet: Erstes Zeichen in der zweiten Zeile.
  lcd.print(h);//Dort soll dann der Text „Viel Erfolg!!!“ auftauchen.
  lcd.print("%");

  
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.print(" *C\n");

  if(h>=40 and h<60)
  {
    analogWrite(GRUEN,255);
   
  }

  if(h>=60 and h<80)
  {
    analogWrite(GELB,255);
  }

  if(h>
  =80 )
  {
    analogWrite(ROT,255);
    delay (500);
    analogWrite(ROT,0);
    delay(500);
  }
  
  
}
