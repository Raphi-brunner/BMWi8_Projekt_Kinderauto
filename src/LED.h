#ifndef LED_H
#define LED_H

#include <FastLED.h>
#include "defines.h"


class LED {
public:
    LED();

    void begin();
    void setModus(uint8_t modus);  // Modus wechseln
    void update();                 // Im loop() aufrufen!

private:
    CRGB     _leds[LED_NUM];
    uint8_t  _modus;
    bool     _blinkZustand;
    uint32_t _letzterBlink;

    // Hilfsfunktionen
    void _allesAus();
    void _bereichFarbe(uint8_t von, uint8_t bis, CRGB farbe);
    void _fahrenAnzeigen();
    void _blinkerUpdate(uint8_t von, uint8_t bis);
};

#endif