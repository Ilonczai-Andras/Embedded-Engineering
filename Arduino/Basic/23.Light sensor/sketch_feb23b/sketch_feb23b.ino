#include <LiquidCrystal.h>

// Define LCD pin connections (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Define sensor and buzzer pins
const int ldrPin = A0;  // LDR connected to analog pin A0
int ldrValue = 0;       // Variable to store LDR value

void setup() {
    lcd.begin(16, 2);  // Initialize the LCD with 16 columns and 2 rows
    pinMode(ldrPin, INPUT);
    Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
    ldrValue = analogRead(ldrPin);  // Read the light level
    Serial.println(ldrValue);       // Print value to serial monitor for debugging

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Light: ");
    lcd.print(ldrValue); // Display light level on LCD

    delay(500); // Small delay before next reading
}
