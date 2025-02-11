
// Define the pins
int waterSensorPin = A0;  // Water level sensor connected to analog pin A0
int ledPin = 13;          // LED connected to digital pin 13

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the input on analog pin 0
  int sensorValue = analogRead(waterSensorPin);

  // Print out the value you read
  Serial.print("Water Level: ");
  Serial.println(sensorValue);

  // Wait for a second before taking the next reading
  delay(1000);
}