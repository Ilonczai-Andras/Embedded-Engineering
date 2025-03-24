// Define the pins for the 74HC595 shift register
#define DATA_PIN 8    // DS (Serial Data Input)
#define LATCH_PIN 9   // ST_CP (Storage Register Clock)
#define CLOCK_PIN 10  // SH_CP (Shift Register Clock)

// Define digit control pins (Assuming they are connected to Arduino)
#define DIGIT_1 2
#define DIGIT_2 3
#define DIGIT_3 4
#define DIGIT_4 5

// Define the segment values for numbers 0-9 (Common Cathode)
const byte digitCodes[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
};

// Numbers to display: D1 = 2, D2 = 3, D3 = 4, D4 = 5
const byte digitsToDisplay[4] = {1,2,3,4};
const byte digitPins[4] = {DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4};

void sendToShiftRegister(byte data) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data);
  digitalWrite(LATCH_PIN, HIGH);
}

void displayDigit(int digit, int position) {
  // Turn off all digits
  for (int i = 0; i < 4; i++) {
    digitalWrite(digitPins[i], HIGH);
  }

  // Send digit data to shift register
  sendToShiftRegister(digitCodes[digit]);

  // Activate the corresponding digit (LOW = ON for transistors)
  digitalWrite(digitPins[position], LOW);

  // Small delay to prevent flickering
  delay(5);
}

void setup() {
  // Set shift register pins as outputs
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);

  // Set digit control pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], HIGH); // Start with all digits off
  }
}

void loop() {
  // Refresh each digit quickly to create persistence of vision effect
  for (int i = 0; i < 4; i++) {
    displayDigit(digitsToDisplay[i], i);
  }
}
