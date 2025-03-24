// Define the 74HC595 shift register pins connected to the Arduino
#define DATA_PIN 12   // DS
#define LATCH_PIN 11  // ST_CP
#define CLOCK_PIN 9  // SH_CP


int photoresistorPin = A0; // Analog pin connected to photoresistor
int threshold = 500;       // Light threshold for turning LEDs on/off

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(photoresistorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(photoresistorPin); // Read the light level
  Serial.print("Light Level: ");
  Serial.println(lightLevel); // Print the value for debugging

  if (lightLevel < threshold) {
    updateShiftRegister(255); // Turn all LEDs ON (11111111 in binary)
  } else {
    updateShiftRegister(0); // Turn all LEDs OFF (00000000 in binary)
  }

  delay(500);
}

// Function to send data to the shift register
void updateShiftRegister(int data) {
  digitalWrite(LATCH_PIN, LOW);  // Prepare shift register for new data
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data); // Send data
  digitalWrite(LATCH_PIN, HIGH); // Update shift register output
}
