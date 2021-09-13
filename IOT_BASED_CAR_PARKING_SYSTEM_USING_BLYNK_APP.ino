//Rudra DIY Crafts 
//Blynk Alert system
#define LED1 D5
#define LED2 D6
#define LED3 D7
#define LED4 D8
#define LED5 D10
#define LED6 D0
#define LED7 D9
#define LED8 A0
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "fpmFFgePbl8D8Mjv_jXVGXMjv0sWQvwv"; //Auth code sent via Email
char ssid[] = "Samsung"; //HotSpot name
char pass[] = "qqqqqqqq";  //HotSpot Password
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(D1);
  if (isButtonPressed==1) {
    Blynk.virtualWrite(V0, 0);
    Blynk.virtualWrite(V5, 250);
    digitalWrite(LED1, LOW);
    digitalWrite(LED5, HIGH);
    Serial.println("Parking 1 is Now available");
    Blynk.notify("Alert : Parking 1 is Now available");
    
  }
  else if (isButtonPressed==0)
  { 
    Blynk.virtualWrite(V0,250);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED5, LOW);
    Blynk.virtualWrite(V5, 0);
    Blynk.notify("Parking 1 is NOT available");
    
  }

//  slot______2
{
  int isButtonPressed = digitalRead(D2);
  if (isButtonPressed==1) {
    Blynk.virtualWrite(V1, 0);
    digitalWrite(LED2, LOW);
    digitalWrite(LED6, HIGH);
    Blynk.virtualWrite(V6, 250);
    Serial.println("Parking 2 is Now available");
    Blynk.notify("Alert : Parking 2 is Now available");
    
  }
  else if (isButtonPressed==0)
  { 
    Blynk.virtualWrite(V1,250);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED6, LOW);
    Blynk.virtualWrite(V6, 0);
    Blynk.notify("Parking 2 is NOT available");
    
  }
  
  
}
//  slot______3

{
  int isButtonPressed = digitalRead(D3);
  if (isButtonPressed==1) {
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V7, 250);
    digitalWrite(LED3, LOW);
    digitalWrite(LED7, HIGH);
    Serial.println("Parking 2 is Now available");
    Blynk.notify("Alert : Parking 3 is Now available");
    
  }
  else if (isButtonPressed==0)
  { 
    Blynk.virtualWrite(V2,250);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED7, LOW);
    Blynk.virtualWrite(V7, 0);
    Blynk.notify("Parking 3 is NOT available");
    
  }
  
  
}

//slot 4

{
  int isButtonPressed = digitalRead(D4);
  if (isButtonPressed==1) {
    Blynk.virtualWrite(V3, 0);
    digitalWrite(LED4, LOW);
    digitalWrite(LED8, HIGH);
    Blynk.virtualWrite(V8, 250);
    Serial.println("Parking 2 is Now available");
    Blynk.notify("Alert : Parking 2 is Now available");
    
  }
  else if (isButtonPressed==0)
  { 
    Blynk.virtualWrite(V3,250);
    Blynk.virtualWrite(V8, 0);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED8, LOW);
    Blynk.notify("Parking 2 is NOT available");
    
  }
  
  
}
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass); 
pinMode(D1,INPUT_PULLUP);
pinMode(D2,INPUT_PULLUP);
pinMode(D3,INPUT_PULLUP);
pinMode(D4,INPUT_PULLUP);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(LED7, OUTPUT);
pinMode(LED8, OUTPUT);



timer.setInterval(1000L,notifyOnThings); 
}
void loop()
{
  Blynk.run();
  timer.run();
}

//er.shubhambhagat@gmail.com
