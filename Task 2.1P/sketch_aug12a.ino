#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "DHT.h"

char ssid[] = "Vihaan";
char pass[] = "Vihaan123";

const char server[] = "api.thingspeak.com";
String writeAPIKey = "65HYD08W52Z7HJBP";

#define DHTPIN 2     
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");

  dht.begin();
}

void loop() { 

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

 String postData = "api_key=" + writeAPIKey + "&field1=" + String(temperature) + "&field2=" + String(humidity);


  if (client.connect(server, 80)) {
    client.println("POST /update HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);
  }
  }
  client.stop();
  delay(15000);
}
