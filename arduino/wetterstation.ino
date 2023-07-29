#include "DHT.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();

  lcd.begin();
  lcd.print("Loading...");
}

void loop() {
  delay(2000);

// Read temperature as humidity
  float h = dht.readHumidity();
  
  // Read temperature as Celsius
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Temperatur:");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(11, 0);
  lcd.print(t);
  lcd.setCursor(11, 1);
  lcd.print(h);
}
