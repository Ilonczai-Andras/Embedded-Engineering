#include <LiquidCrystal.h>

// Initialize the LCD with the pins connected to Arduino
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Print a message to the LCD
  lcd.print("Hello, World!");
}

void loop() {
  // Move the cursor to the second row
  lcd.setCursor(0, 1);
  
  // Print a scrolling message
  lcd.print(millis() / 1000);
  
  // Wait before updating
  delay(1000);
}
