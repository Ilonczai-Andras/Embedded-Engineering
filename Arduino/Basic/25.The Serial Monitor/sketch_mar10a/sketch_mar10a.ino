int stcp_Pin = 4;  // Latch pin (ST_CP)
int shcp_Pin = 3;  // Clock pin (SH_CP)
int ds_Pin = 2;    // Data pin (DS)

void setup()
{
  pinMode(stcp_Pin, OUTPUT);
  pinMode(shcp_Pin, OUTPUT);
  pinMode(ds_Pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter LED Number 0 to 7 or 'x' to clear");
}

void loop() {
  if (Serial.available()) {  // Check if there is input from Serial
    char ch = Serial.read(); // Read the character input
    Serial.println(ch);

    byte ledState = 0b00000000; // Default: All LEDs off

    if (ch >= '0' && ch <= '7') {
      int led = ch - '0'; // Convert char to integer (0-7)
      ledState = (1 << led); // Set the corresponding bit for the LED
    } else if (ch == 'x') {
      ledState = 0b00000000; // Clear all LEDs
    } else {
      Serial.println("Invalid input! Enter 0-7 or 'x' to clear.");
      return;
    }

    // Send data to shift register
    digitalWrite(stcp_Pin, LOW);
    shiftOut(ds_Pin, shcp_Pin, LSBFIRST, ledState);
    digitalWrite(stcp_Pin, HIGH);
  }
}
