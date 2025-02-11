const int tiltSwitchPin = 2;  // Tilt switch connected to digital pin 2

void setup() {
    pinMode(tiltSwitchPin, INPUT);  // Set tilt switch pin as input
    Serial.begin(9600);             // Start serial monitor
}

void loop() {
    int tiltState = digitalRead(tiltSwitchPin);  // Read the tilt switch state

    if (tiltState == HIGH) {
        Serial.println("Tilt detected!");
    } else {
        Serial.println("No tilt detected.");
    }
    
    delay(1000);  // Small delay for stability
}
