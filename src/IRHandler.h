#ifndef IR_HANDLER_H
#define IR_HANDLER_H

#include <Arduino.h>


class IRHandler
{
private:
    uint8_t _pin;

public:
    IRHandler(uint8_t pin);

    void begin();
    void receive();
};

#endif
