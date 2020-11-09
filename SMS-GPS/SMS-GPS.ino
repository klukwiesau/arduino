/*
  GSM Antenne

  braucht 9v / 1A

  AT+CMGF=1 // Textmode an/aus (0) (hexdezi zu lesbar)
  AT+CMGL="ALL"   // alle empfangen SMS auflisten
*/

// Globale initalisierung Hardware

  #include <SoftwareSerial.h>
  SoftwareSerial sim808(10,11);   // 10 und 11 sind die digitalen PINS (TX und RX). Serielle Datenverbindung des GK808 zum Arduino.
  #define DEBUG true      // Debug-Schalter
  String unbekannt, state, timegps, latitude, longitude;  // String-Variablen für GPS-Daten
  char phone_no[] = "xxx";    // Telefonnummer, an die eine SMS gesendet werden soll
  String data[5];         // String-Array mit 5 Einträgen

// einmalige Funktion, die beim Start ausgeführt wird
void setup(){
  sim808.begin(9600); // GK808 soll mit 9600bps beginnen zu senden/empfangen
  Serial.begin(9600); // Serielle Monitor soll mit 9600bps beginnen zu senden/empfangen
  delay(50);    // Pause, damit GK808 reagieren kann - evtl unnötig

  // neu
  sendData("AT", 1000, DEBUG);
  delay(100);  
  sendData("AT+GSV", 1000, DEBUG);
  delay(100);
  sendData("AT+IPR=9600", 1000, DEBUG);
  delay(100); 
  sendData("AT&W", 1000, DEBUG);
  delay(100);  
  sendData("AT+CSQ", 1000, DEBUG);
  delay(100);  
  sendData("ATD10086", 1000, DEBUG);
  delay(100);  
  sendData("ATH", 1000, DEBUG);
  delay(100);  
  // neu - ende

  sendData("AT+CSMP=17,167,0,0", 1000, DEBUG);  // Befehl unbekannt "set this parameter if empty SMS received"
  delay(100);
  sendData("AT+CMGF=1", 1000, DEBUG);   // Textmode an/aus (0) (hexdezi zu lesbar)
  delay(400);

  sendData("AT+CGNSPWR=1", 1000, DEBUG);    // "Power-Supply" des GPS-Moduls aktivieren (externe Stromversorgung oder einfach nur "Anschalten des GPS-Moduls"?)
  delay(50);
  sendData("AT+CGNSSEQ=RMC", 1000, DEBUG);  // Liefert die letzten GPS-Daten. In diesem Fall: RMC - Time, date, position, course and speed data
  delay(150);
}

void loop() {

  sendTabData("AT+CGNSINF", 1000, DEBUG);  // AT-Befehl ausführen und Ergebnis auf data speichern 
  // CGPSINF=0 CGNSINF
  Serial.println("State  :"+state+"|");
  
  if (state != 0 && latitude != "" && longitude != "") {

    Serial.println("unbekannt  :"+unbekannt+"|");   
    Serial.println("State  :"+state+"|");   // Ausgabe in den seriellen Monitor zu Testzwecken
    Serial.println("Time  :"+timegps+"|");
    Serial.println("Latitude  :"+latitude+"|");
    Serial.println("Longitude  :"+longitude+"|");

    sim808.println("AT+CMEE=2");      // Detaillierte Fehlermeldungen
    sim808.println("WAIT=2");    
    delay(2000);

    sim808.println("AT+CPIN=?");      // Abfrage ob PIN ok ist
    sim808.println("WAIT=1");  
    delay(1000);
                
    sim808.print("AT+CMGS=\"");     // SMS senden einleiten
    sim808.print(phone_no);       // Telefonnummer hinzufügen
    sim808.println("\"");       // Befehl abschließen
    sim808.println("WAIT=2");  
    delay(2000);    

    delay(300);
    sim808.print("Ortung erfolgt!\nLink zu Google-Maps:\n");  // zweiter Teil des SMS-Befehls: Text übergeben
    sim808.print("https://www.google.com/maps/place/");
    sim808.print(latitude);
    sim808.print(",");
    sim808.print (longitude);
    delay(200);
    sim808.println((char)26); // End AT command with a ^Z, ASCII code 26  // hier Ende des SMS-Textes. Abschluss mit Sonderzeichen
    delay(200);
    sim808.println();
    delay(15000);
    sim808.flush();

  }else {
    Serial.println("GPS Initialising...");
    delay(5000);
  }
}

// Funktion zum Senden der AT-Befehle und Rückgabe von Fehlermeldungen etc.
// Notwendig, um ggf. Fehler zu erkennen und Befehle automatisch erneute auszuführen, wenn es einen Fehler gab.

String sendData(String command, const int timeout, boolean debug){
  
  String response = "";
  
  sim808.println(command);
  
  long int time = millis();
  int i = 0;

  //while ( (time+timeout ) > millis()){
    while (sim808.available()){
      char c = sim808.read();
      response +=c;
    }
  //}
    
  if (debug) {
     Serial.println(response);
  }
  return response;
}

// Funktion, um AT-Befehle zu senden (inkl. Debug wie bei sendData) und GPS-Daten abzufragen und auszulesen/aufzubereiten.

void sendTabData(String command, const unsigned timeout, boolean debug){

  sim808.println(command);
  delay(500);
  
  unsigned long time = millis();
  int i = 0;
  data[0] = "";
  data[1] = "";
  data[2] = "";
  data[3] = "";
  data[4] = "";

// timeout-Prüfung vorerst ignoriert, weil es zu Abbrüchen in der Ausgabe und evtl. auch bei der Übernahme in die Array-Variablen (data) kommt
  //while (sim808.available() && (millis() - time < timeout) && i<5){
  while (sim808.available() && i<5){
      char c = sim808.read();
      if (debug){
        Serial.write(c);
      }

      if (c != ','){
        data[i] += c;
        delay(100);
      }else{
        i++;
      }          
  }

// wir sind hier nicht mehr innerhalb der Schleife, sondern NACH der Schleife.
  //if(i==5){
    unbekannt = data[0];  // ist vermutlich nur der letzte Befehl, der an sim808 ging - wird ignoriert im Code
    state = data[1];
    timegps = data[2];
    latitude = data[3];
    longitude = data[4];     
//  }
  


  if (debug){
    Serial.println(data[0] + "," + data[1] + "," + data[2] + "," + data[3] + "," + data[4]);
  }

}
  
