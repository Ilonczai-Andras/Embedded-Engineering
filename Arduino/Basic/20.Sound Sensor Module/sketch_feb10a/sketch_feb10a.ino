#define ANALOG_PIN A0  // KY-037 Analog output connected to A0
#define DIGITAL_PIN 2  // KY-037 Digital output connected to D2
#define LED_PIN 13     // LED connected to D13 (optional)

int soundThreshold = 600;  // Adjust this based on noise level

void setup() {
    pinMode(DIGITAL_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int analogValue = analogRead(ANALOG_PIN); // Read analog sound level
    int digitalValue = digitalRead(DIGITAL_PIN); // Read digital output (0 or 1)

    Serial.print("Analog Value: ");
    Serial.print(analogValue);
    Serial.print(" | Digital Value: ");
    Serial.println(digitalValue);

    if (analogValue > soundThreshold || digitalValue == HIGH) {
        digitalWrite(LED_PIN, HIGH); // Turn on LED when sound is detected
    } else {
        digitalWrite(LED_PIN, LOW);  // Turn off LED
    }

    delay(100); // Small delay to stabilize readings
}
