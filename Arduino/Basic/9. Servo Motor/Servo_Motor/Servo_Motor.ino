#include <Servo.h>  // Include the Servo library

Servo myServo;  // Create a servo object

int servoPin = 9;  // Define the PWM pin connected to the servo

void setup() {
    myServo.attach(servoPin);  // Attach the servo to pin 9
}

void loop() {
    // Move servo from 0° to 180°
    for (int pos = 0; pos <= 180; pos++) {
        myServo.write(pos);  // Set servo position
        delay(15);  // Small delay to allow movement
    }

    // Move servo from 180° back to 0°
    for (int pos = 180; pos >= 0; pos--) {
        myServo.write(pos);
        delay(15);
    }
}
