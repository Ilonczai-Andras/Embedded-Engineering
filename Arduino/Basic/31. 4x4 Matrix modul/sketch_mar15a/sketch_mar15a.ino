#include <Keypad.h>

// Define the number of rows and columns
const byte ROWS = 4; 
const byte COLS = 4; 

// Define the keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the row and column pins
byte rowPins[ROWS] = {5, 6, 7, 8}; 
byte colPins[COLS] = {1, 2, 3, 4}; 

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
