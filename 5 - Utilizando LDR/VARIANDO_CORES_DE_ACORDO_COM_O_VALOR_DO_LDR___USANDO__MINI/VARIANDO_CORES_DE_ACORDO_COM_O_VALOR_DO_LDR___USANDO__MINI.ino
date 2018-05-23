int ldrPin = A0;
int ledb =13;
int ledr = 15;
int ledg = 12;

void setup() {

Serial.begin(9600);

pinMode(ledb,OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(ledr, OUTPUT);
pinMode(ledg, OUTPUT);
}

void loop() {

int ldrStatus = analogRead(ldrPin);

Serial.println(ldrStatus);

if(ldrStatus<=340)
{
  digitalWrite(ledr,HIGH);
  
  delay(500);
  digitalWrite(ledr,LOW);
  }
else if (ldrStatus >340&& ldrStatus <=680)
{
  digitalWrite(ledg,HIGH);
  delay(500);
  digitalWrite(ledg,LOW);
  }
else if (ldrStatus > 680 )
{
  digitalWrite(ledb,HIGH);
  delay(500);
  digitalWrite(ledb,LOW);
  }



}
