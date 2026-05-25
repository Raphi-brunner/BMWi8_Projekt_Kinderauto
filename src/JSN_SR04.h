// JSN_SR04.h
#ifndef JSN_SR04_H
#define JSN_SR04_H

#include <Arduino.h>

class Sensor {
private:
    uint8_t trigger_pin;
    uint8_t echo_pin;
    const char* name;

public:
    Sensor(uint8_t trig, uint8_t echo, const char* sensor_name);
    void begin();
    float measure();
};

#endif