#include <Servo.h>
#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT22
const int PrCa = 3;
const int PrIn = 4;
const int IR =  5;
Servo myservo;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
pinMode(PrCa,1);
pinMode(PrIn,1);
pinMode(IR,1);
myservo.attach(9);
Serial.begin(9600);
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile int a = digitalRead(PrCa);
  volatile int b = digitalRead(PrIn);
  volatile int c = digitalRead(IR);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  if(a==0){
    if(b==0){
      myservo.write(30);  //Plastic
            }
      else{
        myservo.write(100); //Metal
      }
  }
  if(a==1){
    if(b==1){
      if(h>40){
        myservo.write(150);//organic 
      }
      else{
          myservo.write(180); //Glass
        }
  }
  }
  }
