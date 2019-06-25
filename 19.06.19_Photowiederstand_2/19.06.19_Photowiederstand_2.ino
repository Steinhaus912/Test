int eingang= A7; //Das Wort „eingang“ steht jetzt für den Wert „A7“ (Bezeichnung vom Analogport 7)
int LED = 7; //Das Wort „LED“ steht jetzt für den Wert 7
int sensorWert = 0; //Variable für den Sensorwert mit 0 als Startwert

void setup()//Hier beginnt das Setup.
{
Serial.begin(9600); //Die Kommunikation mit dem seriellen Port wird gestartet. Das benötigt man, um sich den tatsächlich ausgelesenen Wert später im serial monitor anzeigen zu lassen.
pinMode (LED, OUTPUT); //Der Pin mit der LED (Pin 7) ist jetzt ein Ausgang
//Der analoge Pin muss nicht definiert werden.
}

void loop()
{
sensorWert =analogRead(eingang); //Die Spannung an dem Fotowiderstand auslesen und unter der Variable „sensorWert“ abspeichern.
Serial.print("   Sensorwert = " ); //Ausgabe am Serial-Monitor: Das Wort „Sensorwert: „
Serial.println(sensorWert); //Ausgabe am Serial-Monitor. Mit dem Befehl Serial.print wird der Sensorwert des Fotowiderstandes in Form einer Zahl zwischen 0 und 1023 an den serial monitor gesendet.

if (sensorWert > 512 ) //Wenn der Sensorwert über 512 beträgt….
{
digitalWrite(LED, HIGH); 
}

else 
{
digitalWrite(LED, LOW); 
}

delay (50);//Eine kurze Pause, in der die LED an oder aus ist

//ab hier: Verarbeitung der Sensorwerte
// Unterteilung des Wertebereichs der Helligkeit in 5 Kategorien

if (sensorWert < 204 )//sehr dunkel
  {
    Serial.print("Sonnenschutz: --");
  }

if (sensorWert >204 && sensorWert < 408)//etwas heller aber noch nahezu dunkel
  {
    Serial.print("Sonnenschutz: -");
  }
if (sensorWert > 408 && sensorWert < 612)//hell, vergleichbar mit im Schatten vorm Tentomax sitzend
  {
    Serial.print("Sonnenschutz: o");
  }
if (sensorWert > 612 && sensorWert < 816)//hell, direkte Sonneneinstrahlung
  {
    Serial.print("Sonnenschutz: +");
  }
if (sensorWert > 816 )//sehr hell, direkte Sonneneinstrahlung
  {
    Serial.print("Sonnenschutz: ++");
  }

}
