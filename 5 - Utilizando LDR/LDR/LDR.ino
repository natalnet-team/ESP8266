
const int ledPin = 5;
const int ldrPin = A0;

void setup() {

Serial.begin(9600);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrStatus = analogRead(ldrPin);

if (ldrStatus <=40) {

digitalWrite(ledPin, HIGH);
Serial.print(ldrStatus);
Serial.println("Luzes ligadas, está anoitecendo");

}

else {

digitalWrite(ledPin, LOW);
Serial.println("Luzes desligadas, está de dia");

}

}
