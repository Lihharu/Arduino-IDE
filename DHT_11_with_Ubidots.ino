#include "DHT.h"
#include "UbidotsMicroESP8266.h"
#define DHTPIN 4//pin sensor DHT
#define TOKEN "BBFF-2VzxgaA6hWYlv7aC9cx1JGFQBoLzqe"
#define ssid "eskrim_plus"
#define psswd "kiyanumar123"
 DHT dht(DHTPIN,DHT11);
 Ubidots client(TOKEN);
 unsigned long last =0;
 
 
void setup() {
 
  Serial.begin(9600);
  dht.begin();
  delay(20);
  client.wifiConnection(ssid,psswd);  // klau ssid memakai pass
 
  //  client.wifiConnection(ssid,NULL); // klau ssid tdk memakai pass
 
}
 
void loop() {
  if(millis()-last>1000){
    float hum = dht.readHumidity();
    float temp = dht.readTemperature();
    last=millis();
    client.add("kelembaban",hum);
    client.add("Temperature",temp);
    client.sendAll(true);
  }
}
