#include "IRHandler.h"
#include <IRremote.hpp>

IRHandler::IRHandler(uint8_t pin) : _pin(pin) {}

void IRHandler::begin() {
    IrReceiver.begin(_pin, ENABLE_LED_FEEDBACK);
    Serial.println("IR-Empfänger gestartet...");
}

uint32_t IRHandler::receive() {

    if (!IrReceiver.decode()) {
        return 0;
    }

    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("HEX-Code: 0x");
    Serial.println(code, HEX);

    IrReceiver.resume();

    return code;
}