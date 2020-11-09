
// GPS Modul <-> Arduino
// GRD - GRD
// RX - 8
// TX - 7
// K - ?
// VCC - 5V
// GRD - GRD
// Sleep - ?
// https://cdn.instructables.com/ORIG/FAO/80RU/IXLALERK/FAO80RUIXLALERK.pdf

#include <NOKIA5110_TEXT.h>
#include <SoftwareSerial.h>



SoftwareSerial sim808(7,8);
char phone_no[] = "xxx"; // replace with your phone no.
String data[5];
#define DEBUG true
String state,timegps,latitude,longitude;

//LCD Nokia 5110 pinout left to right
// RST 1/ CE 2/ DC 3/ DIN 4/ CLK 5 / VCC 6 /LED 9 /GND 8
NOKIA5110_TEXT mylcd(2, 3, 4, 5, 6);
#define inverse  false // set to true to invert display pixel color
#define contrast 0xB1 // default is 0xBF set in LCDinit, Try 0xB1<-> 0xBF if your display is too dark
#define bias 0x12 // LCD bias mode 1:48: Try 0x12 or 0x13 or 0x14
#define FontNumber 1 //1-6, 1 is default ,  Comment in  defines at top of  NOKIA5110_TEXT.h if using non default
static const byte ledPin = 9;

int iLoops = 0;

void setup() {
  delay(1000);
  mylcd.LCDInit(inverse, contrast, bias); // init  the lCD
  mylcd.LCDClear(0x00); // Clear whole screen
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  mylcd.LCDFont(FontNumber); // Set the font
 
 sim808.begin(9600);
 Serial.begin(9600);
 delay(50);

 sim808.print("AT+CSMP=17,167,0,0\r");  // set this parameter if empty SMS received
 delay(100);
 sim808.print("AT+CMGF=1\r");
 delay(400);

 sendData("AT+CGNSPWR=1",1000,DEBUG);
 delay(50);
 sendData("AT+CGNSSEQ=RMC",1000,DEBUG);
 delay(150);

}

void loop() {
/*
  mylcd.LCDgotoXY(0, 0); // (go to (X , Y) (0-84 columns, 0-5 blocks) top left corner
  mylcd.LCDString("GPS Init...."+iLoops);
*/  
  sendTabData("AT+CGNSINF",1000,DEBUG);
  if (state !=0) {
    Serial.println("State  :"+state);
    Serial.println("Time  :"+timegps);
    Serial.println("Latitude  :"+latitude);
    Serial.println("Longitude  :"+longitude);
/*
    mylcd.LCDString("St|Ti|La|Lo");
    mylcd.LCDgotoXY(0, 1);
    mylcd.LCDString(state.c_str());
    mylcd.LCDgotoXY(0, 2);
    mylcd.LCDString(timegps.c_str());
    mylcd.LCDgotoXY(0, 3);
    mylcd.LCDString(latitude.c_str());
    mylcd.LCDgotoXY(0, 4);
    mylcd.LCDString(longitude.c_str());
    mylcd.LCDgotoXY(0, 5);
    mylcd.LCDString("Loops: "+iLoops);
*/

    sim808.println("AT+CMEE=2");
    sim808.println("WAIT=2");    
    delay(2000);
    

    sim808.println("AT+CPIN=?");
    sim808.println("WAIT=2");  
    delay(2000);
        
    sim808.print("AT+CMGS=\"");
    sim808.print(phone_no);
    sim808.println("\"");
    sim808.println("WAIT=2");  
    delay(2000);


    //sim808.println("AT+CPIN=\"7868?");
    
    
/*
    delay(300);
    Serial.print("LOCATION SUCCESSFULLY FOUND!\nPlease use Google Maps link provided below.\n");
    Serial.print("http://www.google.com/maps/place/");
    Serial.print(latitude);
    Serial.print(",");
    Serial.print (longitude);
    delay(200);
    Serial.println();
*/

    delay(300);
    sim808.print("LOCATION SUCCESSFULLY FOUND!\nPlease use Google Maps link provided below.\n");
    sim808.print("http://www.google.com/maps/place/");
    sim808.print(latitude);
    sim808.print(",");
    sim808.print (longitude);
    delay(200);
    sim808.println((char)26); // End AT command with a ^Z, ASCII code 26
    delay(200);
    sim808.println();
    delay(5000);
    sim808.flush();

  } else {
    Serial.println("GPS Initialising...");
    
    iLoops++;
  }
}

void sendTabData(String command , const unsigned timeout , boolean debug){
  sim808.println(command);
  unsigned long time = millis();
  int i = 0;
  data[0] = "";
  data[1] = "";
  data[2] = "";
  data[3] = "";
  data[4] = "";

  while (millis() - time < timeout){
    while (sim808.available()){
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
      
      if (i == 5){
        state = data[1];
        timegps = data[2];
        latitude = data[3];
        longitude = data[4];
        delay(100);
        goto exitL;
      }
      
    }
  }

exitL:
  if (debug){
    Serial.println(data[0] + "," + data[1] + "," + data[2] + "," + data[3] + "," + data[4]);
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
     Serial.print(response);
  }
     return response;
}
