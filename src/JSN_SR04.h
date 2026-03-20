#ifndef JSN_SR04_H
#define JSN_SR04_H

#include <Arduino.h>


class JSN_SR04
{
private:
    uint8_t _TRIG;
    uint8_t _ECHO;

    unsigned long echoZeit = 0;
    float distanz = 0.0;
    
public:
    JSN_SR04(uint8_t TRIG, uint8_t ECHO);

    void begin();
    void distance();
};

#endif