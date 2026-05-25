// JSN_SR04.cpp
#include "JSN_SR04.h"

Sensor::Sensor(uint8_t trig, uint8_t echo, const char* sensor_name)
    : trigger_pin(trig), echo_pin(echo), name(sensor_name) {}

void Sensor::begin()
{
    pinMode(trigger_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
    digitalWrite(trigger_pin, LOW);
}

float Sensor::measure()
{
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(200);
    digitalWrite(trigger_pin, LOW);

    while (digitalRead(echo_pin) == LOW);
    unsigned long echo_start = micros();
    while (digitalRead(echo_pin) == HIGH);
    unsigned long echo_time = micros() - echo_start;

    return (echo_time * 0.0343) / 2.0;
}