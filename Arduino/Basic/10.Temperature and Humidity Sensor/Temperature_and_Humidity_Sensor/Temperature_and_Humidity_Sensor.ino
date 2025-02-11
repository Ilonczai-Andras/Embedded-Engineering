#include <DHT.h>

#define DHTPIN 2      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // Change to DHT22 if using a DHT22 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    Serial.println("DHT Sensor Reading...");
    dht.begin();
}

void loop() {
    float temp = dht.readTemperature();  // Get temperature in Celsius
    float humidity = dht.readHumidity(); // Get humidity

    if (isnan(temp) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000); // Wait 2 seconds before reading again
}
