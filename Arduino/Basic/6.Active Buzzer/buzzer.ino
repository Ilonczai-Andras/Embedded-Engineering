// Define the pin where the buzzer is connected
const int buzzerPin = 9;  // Connect the active buzzer to pin 9

void setup() {
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn the buzzer on
  digitalWrite(buzzerPin, HIGH);
  delay(500); // Keep the buzzer on for 500 milliseconds
}
