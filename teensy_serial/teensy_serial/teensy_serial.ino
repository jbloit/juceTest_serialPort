
const int ledPin = 13;      // the pin that the LED is attached to

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    // initialize the ledPin as an output:
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.write(100);
  //delay(1000);

  int incomingByte;

          
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("USB received: ");
    Serial.println(incomingByte, DEC);
/*
    if (incomingByte > 60)
    {
      digitalWrite(ledPin, HIGH);
    } 
    else 
    {
    digitalWrite(ledPin, LOW);
    }
    */

  }
}
