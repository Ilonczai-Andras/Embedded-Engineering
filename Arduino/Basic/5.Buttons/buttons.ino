// *Interfacing RGB LED with Arduino 
// * Author: Osama Ahmed 

//Defining  variable and the GPIO pin on Arduino
int buttonApin= 9;
int buttonBpin = 8;
int ledPin = 5;

void setup() {
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}
void  loop() {
  if (digitalRead(buttonApin) == LOW)
  {
  digitalWrite(ledPin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW)
  {
  digitalWrite(ledPin, LOW);
  }

}

