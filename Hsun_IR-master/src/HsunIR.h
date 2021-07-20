/**
 * @file      HsunIR.h
 * @author    Hsun
 * @brief 
 * @version   0.1
 * @date      2021-07-16
 * 
 * @copyright Copyright © 2021
 * 
 */
#include <Arduino.h>

#ifndef __HSUN_IR_H__
#define __HSUN_IR_H__

    #define IR_POWER              -0.952
    #define IR_COEFFICIENT         10782.0f
    #define IR_CONSTANT           -1.9f

    #define HSUN_IR_ERROR          0x00
    #define HSUN_IR_OK             0x01
    
    // If you want to show debug.
    // Please define HSUN_IR_DEBUG.
    // #define HSUN_IR_DEBUG

    class HsunIR {
        private:
            uint8_t  _pin;
            double   _power;
            float    _coefficient;
            float    _constant;

        public:
            /**
             * @brief Construct a new Hsun IR object
             * 
             * @param pin Enter your IR PIN (ADC)
             */
            HsunIR(uint8_t pin);

            /**
             * @brief Calibration your parameter.
             * 
             * @param power        => power
             * @param coefficient  => coefficient
             * @param constant     => constant
             * @return uint8_t */
            uint8_t begin      (float power = IR_POWER, float coefficient = IR_COEFFICIENT, float constant = IR_CONSTANT);
            float   getDistance();
    };
 
#endif
