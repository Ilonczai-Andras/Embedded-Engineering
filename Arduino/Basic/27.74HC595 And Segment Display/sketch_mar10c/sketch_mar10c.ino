// Pin connections to the 74HC595 shift register
#define DATA_PIN 2   // DS (SER) - Serial Data Input
#define LATCH_PIN 3  // ST_CP (RCLK) - Storage Register Clock
#define CLOCK_PIN 4  // SH_CP (SRCLK) - Shift Register Clock

// 7-segment display common cathode digit mappings (adjusted to your wiring)
const byte digits[16] = {
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
  0b00110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001,  // F
};

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
    for(int i = 0; i <= 15; i++)
    {
      displayDigit(i);
      delay(1000);
    }

}

void displayDigit(byte num) {
  digitalWrite(LATCH_PIN, LOW); // Prepare shift register for data input
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, digits[num]); // Send data to shift register
  digitalWrite(LATCH_PIN, HIGH); // Latch data to output
}
