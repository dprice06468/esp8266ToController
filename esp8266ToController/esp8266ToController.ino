#include <SoftwareSerial.h>

/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 *
 * Please be sure to select the right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int pinTx = 22;
int pin16 = 16;
int intBlinkRate = 0;
boolean booBlink = false;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "418191e310a8494c83c8a91531542d06";

//-------------------------------------------------
void setup()
{
  Serial.begin(115200);
  pinMode(pin16, OUTPUT);
  
  Blynk.begin(auth, "pricelan", "candyman");
  Serial.println("esp8266ToController");
}

//-------------------------------------------------
//change color to red
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$R");
    //blinkPin();
  }
}

//-------------------------------------------------
//change color to green
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$G");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//change color to blue
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$B");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//change color to white
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$W");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//change color to black
BLYNK_WRITE(V4)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$K");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//play sound 0
BLYNK_WRITE(V5) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("##0");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//play sound 1
BLYNK_WRITE(V6) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("##1");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//trigger lightning
BLYNK_WRITE(V7) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("$z");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//trigger voldemorte
BLYNK_WRITE(V8) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("##0,$z");
    if (booBlink) blinkPin();
  }
}

//-------------------------------------------------
//trigger RGB
BLYNK_WRITE(V9) 
{
  if (param.getLength() < 5)
     return;

  byte red = param[0].asInt();
  byte green = param[1].asInt();
  byte blue = param[2].asInt();

  Serial.println("%r" + (String)red + "g" + (String)green + "b" + (String)blue);
  if (booBlink) blinkPin();
}

//-------------------------------------------------
//trigger blinking
BLYNK_WRITE(V10) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    Serial.println("blinking on");
    booBlink = true;
  } else {
    Serial.println("blinking off");
    booBlink = false;
  }
}

//-------------------------------------------------
void loop()
{
  Blynk.run();
}

//-------------------------------------------------
void blinkPin() {
  for (byte i=0; i<2; i++) {
    digitalWrite(pin16, HIGH); 
    delay(150);                   
    digitalWrite(pin16, LOW);  
    delay(150);   
  }                
}

