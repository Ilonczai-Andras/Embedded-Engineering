//For more Projects: www.arduinocircuit.com
int led = 13 ; // LED on arduino
int digitalPin = 3; // linear Hall magnetic sensor digital interface
int digitalVal ; // digital readings
void setup ()
{
  pinMode (led, OUTPUT);
  pinMode (digitalPin, INPUT);
  //pinMode(analogPin, INPUT);
  Serial.begin(9600);
}
void loop ()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin) ;
  Serial.println(digitalVal);
  if (digitalVal == HIGH) // When magnetic field is present, Arduino LED is on
  {
    digitalWrite (led, HIGH);
   
  }
  else
  {
    digitalWrite (led, LOW);
  }
  delay(100);
}