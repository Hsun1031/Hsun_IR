#include <Arduino.h>
#include <HsunIR.h>

#define IR_PIN 32

HsunIR IR(IR_PIN);

void setup() {
    Serial.begin(115200);
    Serial.println("\n");
    
    IR.begin();
}

void loop() {
    Serial.printf("Distance: %.2f\n", IR.getDistance());
    delay(1000);
}