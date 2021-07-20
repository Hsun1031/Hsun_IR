# Hsun IR

**This library is for ESP32.**

## Module

* GP2Y0A41SK0F

## How to use?

* HsunIR
Construct a new Hsun IR object
  * pin Enter your IR PIN (ADC)

```cpp
HsunIR(uint8_t pin);
```

* begin
Calibration your parameter.
  * power        => power
  * coefficient  => coefficient
  * constant     => constant
  * return uint8_t

```cpp
begin (float power = -0.952, float coefficient = 10782.0f, float constant = -1.9f);

/****************************************************************************************************/

uint16_t value    =  analogRead(_pin);

float    distance = (value    == 0)? 31   : (_coefficient * (float)pow(value, _power) + _constant);
         distance = (distance  < 4)? 3.0f : ((distance > 30)? 31.0f : distance);
```

* getDistance
  * Get Distance

```cpp
getDistance();
```
