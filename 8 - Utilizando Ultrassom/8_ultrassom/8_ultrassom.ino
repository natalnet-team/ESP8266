#include <hcsr04.h>

#define TRIG_PIN 5 // D1
#define ECHO_PIN 4 // D2

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup(){
    Serial.begin(115200);
}

void loop() {
    Serial.println(hcsr04.distanceInMillimeters());
    delay(10);
}
