const int redPin = 9;    // Connect the R pin to digital pin 9
const int greenPin = 10; // Connect the G pin to digital pin 10
const int bluePin = 11;  // Connect the B pin to digital pin 11

void setup() {
  // Set the pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Call the function to display different colors
  displayColor(255, 0, 0);   // Red
  delay(1000);               // Wait for 1 second
  displayColor(0, 255, 0);   // Green
  delay(1000);
  displayColor(0, 0, 255);   // Blue
  delay(1000);
  displayColor(255, 255, 0); // Yellow
  delay(1000);
  displayColor(0, 255, 255); // Cyan
  delay(1000);
  displayColor(255, 0, 255); // Magenta
  delay(1000);
  displayColor(255, 255, 255); // White
  delay(1000);
}

// Function to display a specific color
void displayColor(int redValue, int greenValue, int blueValue) {
  // Apply PWM (Pulse-Width Modulation) to each pin to control the color intensity
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}