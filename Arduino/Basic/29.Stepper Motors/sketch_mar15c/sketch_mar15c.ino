#include <Stepper.h>

// Define the number of steps per revolution (change this based on your motor)
#define STEPS_PER_REV 2048  

// Define the pins for the stepper motor driver (ULN2003)
#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

// Initialize the stepper library on the defined pins
Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
    stepper.setSpeed(10);  // Set motor speed (RPM)
    Serial.begin(9600);
}

void loop() {
    Serial.println("Rotating Clockwise...");
    stepper.step(STEPS_PER_REV);  // Rotate one full revolution clockwise
    delay(1000);  

    Serial.println("Rotating Counterclockwise...");
    stepper.step(-STEPS_PER_REV); // Rotate one full revolution counterclockwise
    delay(1000);  
}
