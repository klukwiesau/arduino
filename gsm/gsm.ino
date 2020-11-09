
// GPS Modul <-> Arduino
// GRD - GRD
// RX - 8
// TX - 7
// K - ?
// VCC - 5V
// GRD - GRD
// Sleep - ?
// https://cdn.instructables.com/ORIG/FAO/80RU/IXLALERK/FAO80RUIXLALERK.pdf

#include <SoftwareSerial.h>



SoftwareSerial sim808(7,8);
char phone_no[] = "01786109486"; // replace with your phone no.
String data;
String state;
#define DEBUG true


void setup() {
 
 sim808.begin(9600);
 Serial.begin(38400);
 delay(50);

 //sim808.print("AT+CSMP=17,167,0,0\r");  // set this parameter if empty SMS received
 //delay(100);
 //sim808.print("AT+CMGF=1\r");
 //delay(400);

 sendData("AT+CGNSPWR=1", 1000, DEBUG); // command returns the current status of GNSS power supply. -> Status für GPS
 delay(1050);
 sendData("AT+CGNSSEQ=RMC", 1000, DEBUG); // command returns the current setting of last sentence parsed -> GPS-Parameter abfragen (RMC)
 delay(1050);


    

}

void loop() {



    sendData("AT+CMEE=2", 2000, DEBUG); // Mehr Details zum Fehler ausgeben -> erweiterte Debug-Infos
    delay(2050);

    sendData("AT+CPIN=?", 2000, DEBUG); // PIN-Status prüfen. Über weiter Parameter kann die PIN eingegeben, geändert oder deaktiviert werden.
    delay(2050);    
/*    
        
    sim808.print("AT+CMGS=\"");
    sim808.print(phone_no);
    sim808.println("\"");
    sim808.println("WAIT=20");  
*/

    

//    sim808.flush();

}

void sendTabData(String command , const unsigned timeout , boolean debug)
{
  sim808.println(command);
  unsigned long time = millis();
  int i = 0;
  data = "";


  while (millis() - time < timeout)
  {
    while (sim808.available())
    {
      char c = sim808.read();


      if (debug)
      {
        Serial.write(c);
      }


      if (c != ',')
      {
        data[i] += c;
        delay(100);
      }
      else
      {
        i++;
      }
      if (i == 5)
      {
        state = data;
        delay(100);
        goto exitL;
      }
    }
  }


exitL:
  if (debug)
  {
    Serial.println(data);
  }
}

String sendData (String command , const int timeout ,boolean debug){
  String response = "";
  sim808.println(command);
  long int time = millis();
  int i = 0;

  while ( (time+timeout ) > millis()){
    while (sim808.available()){
      char c = sim808.read();
      response +=c;
    }
  }
  
  if (debug) {
     Serial.println("response: "+response);
  }
  return response;
}
