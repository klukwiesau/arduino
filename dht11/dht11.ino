/* 
   DHT11 Temperature and Humidity Sensor With Arduino
   For more details, visit: https://techzeero.com/arduino-tutorials/dht11-with-arduino/
*/

#include <dht.h>

#define dht_pin A0     // Analog Pin A0 of Arduino is connected to DHT11 out pin
 
dht DHT;
float temp, hum;
boolean fanIsRunning=false;
 
void setup()
{
  pinMode(7, OUTPUT); // Relais-Schalter
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
}
 
void loop()
{
    
    DHT.read11(dht_pin);
    temp = DHT.temperature;
    hum = DHT.humidity;
    Serial.print("Humidity = ");
    Serial.print(hum);
    Serial.print("%    ");
    Serial.print("Temperature = ");
    Serial.print(temp); 
    Serial.println(" C");

    if(temp>22 || hum>60){
        Serial.println("Es ist zu warm oder zu feucht!");
        if(!fanIsRunning){
          Serial.println("-> Lüfter: AN!");
          digitalWrite(7, HIGH);
          fanIsRunning=true;
      }else{
        Serial.println("-> Lüfter laufen lassen...");
      }
    }else if(fanIsRunning){
      Serial.println("Luft ist wieder i.O. - Lüfter: AUS!");
      digitalWrite(7, LOW);
      fanIsRunning=false;
    }
    
    delay(5000);
    
    //digitalWrite(7, HIGH); //Und wieder ausschalten
    //delay(4000); //Reduce Time for Quick Reply 
    //digitalWrite(7, LOW); //An dieser Stelle würde das Relais einsschalten
    //delay(2500);//...eine Sekunde warten
    
}
