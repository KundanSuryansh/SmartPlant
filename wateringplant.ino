/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your auth token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Your Wifi ID";
char pass[] = "Wifi Password";
long timeValue;
long startValue;
WidgetLED led1(V1);
WidgetLED led2(V2);
BLYNK_WRITE(V0) //input from Numeric Widget
{
  timeValue = param[0].asLong();
}
BLYNK_WRITE(V3) //input from Numeric Widget
{
  startValue = param[0].asLong();
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
 int ledValue=digitalRead(D3);
 Serial.print("start value : ");
 Serial.println(startValue);
 led2.off();
 if(startValue==1){
  digitalWrite(D0, 1);
  Serial.println("D0 pin is high.");
  if(timeValue!=0){
    int delayTime=1000*timeValue;
    led2.on();
    delay(delayTime);
    digitalWrite(D0, 0);
    Blynk.virtualWrite(V3, 0);
    startValue=0;
    led2.off();
  }
  else{
    led2.on();
    delay(10000);
    digitalWrite(D0, 0);
    Blynk.virtualWrite(V3, 0);
    startValue=0;
    led2.off();
  }
 }
  Serial.println("LED on V1: off");
  led1.off();
  if(ledValue==1){
    led1.on();
    Serial.println(ledValue);
    Serial.println("LED on V1: on");
  }
  Blynk.run();
}

