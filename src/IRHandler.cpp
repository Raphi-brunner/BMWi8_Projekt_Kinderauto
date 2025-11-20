#include "IRHandler.h"
#include <IRremote.hpp>
IRHandler::IRHandler(uint8_t pin) : _pin(pin) {}

void IRHandler::begin() {
    IrReceiver.begin(_pin, ENABLE_LED_FEEDBACK);
    Serial.println("IR-Empfänger gestartet...");
}

void IRHandler::receive() {
    if (!IrReceiver.decode()) return;

    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("HEX-Code: 0x");
    Serial.println(code, HEX);

    /*
    if (code == 0xFA053000) {
        Serial.println("Hallo");
    }
    */

    IrReceiver.resume();
}
