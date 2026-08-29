#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  float humidity = dht.readHumidity();
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);

  delay(2000);
}
