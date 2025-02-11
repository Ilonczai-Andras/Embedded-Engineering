#define VRX_PIN A0  // Joystick X-axis
#define VRY_PIN A1  // Joystick Y-axis
#define SW_PIN  2   // Joystick push button

void setup() {
    Serial.begin(9600);  // Start serial communication
    pinMode(SW_PIN, INPUT_PULLUP); // Use internal pull-up resistor for the button
}

void loop() {
    int xValue = analogRead(VRX_PIN);  // Read X-axis value (0-1023)
    int yValue = analogRead(VRY_PIN);  // Read Y-axis value (0-1023)
    int buttonState = digitalRead(SW_PIN); // Read button state (LOW = Pressed)

    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" | Y: ");
    Serial.print(yValue);
    Serial.print(" | Button: ");
    Serial.println(buttonState == LOW ? "Pressed" : "Released");

    delay(100); // Small delay to make readings readable
}
