// Define the pin where the passive buzzer is connected
const int buzzerPin = 9; // Connect the passive buzzer to pin 9

void setup() {
  // No setup required for the passive buzzer
}

void loop() {
  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 523); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 587); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 659); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 698); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 784); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 880); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 988); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds

  // Play a tone at 1000 Hz for 500 milliseconds
  tone(buzzerPin, 1074); // 1000 Hz is the frequency
  delay(500); // Wait for 500 milliseconds
}
