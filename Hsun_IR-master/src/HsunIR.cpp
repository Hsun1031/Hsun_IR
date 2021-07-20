#include <HsunIR.h>

HsunIR::HsunIR(uint8_t pin){
    _pin = pin;
}

uint8_t HsunIR::begin(float power, 
                      float coefficient, 
                      float constant) {
    _power       = power;
    _coefficient = coefficient;
    _constant    = constant;

    return HSUN_IR_OK;
};

float HsunIR::getDistance() {
    uint16_t value    =  analogRead(_pin);

    float    distance = (value    == 0)? 31   : (_coefficient * (float)pow(value, _power) + _constant);
             distance = (distance  < 4)? 3.0f : ((distance > 30)? 31.0f : distance);

#ifdef HSUN_IR_DEBUG
    printf("analogRead[%d]: %d\n",   _pin, analogRead(_pin));
    printf("  distance[%d]: %.2f\n", _pin, distance);
    printf("\n");
#endif

    return distance;
}
