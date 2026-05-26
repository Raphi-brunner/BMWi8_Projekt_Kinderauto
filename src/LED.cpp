#include "LED.h"
#include <Arduino.h>


CRGB leds[LED_NUM];

LED::LED()
    : _modus(MODUS_AUS),
      _blinkZustand(false),
      _letzterBlink(0) {}

void LED::begin() {
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_NUM);
    FastLED.setBrightness(LED_HELLIGKEIT);
    _leds[0]; 
    _allesAus();
    Serial.println("LED-Streifen initialisiert (60 LEDs)");
}

void LED::setModus(uint8_t modus) {
    _modus        = modus;
    _blinkZustand = false;
    _letzterBlink = 0;

    Serial.print("LED Modus: ");
    Serial.println(modus);

    switch (_modus) {
        case MODUS_AUS:
            _allesAus();
            break;

        case MODUS_FAHREN:
            _allesAus();
            // Scheinwerfer vorne: warmweiß
            _bereichFarbe(FRONT_START, FRONT_END, CRGB(255, 255, 220));
            // Rücklicht hinten: rot (gedimmt)
            _bereichFarbe(HECK_START, HECK_END, CRGB(120, 0, 0));
            // Ambiente Mitte: schwaches Blau
            _bereichFarbe(15, 44, CRGB(0, 0, 30));
            FastLED.show();
            break;

        case MODUS_RUECKWAERTS:
            _allesAus();
            // Rückfahrlicht hinten: kaltweiß hell
            _bereichFarbe(HECK_START, HECK_END, CRGB(255, 255, 255));
            // Vorne gedimmt rot als Warnung
            _bereichFarbe(FRONT_START, FRONT_END, CRGB(80, 0, 0));
            FastLED.show();
            break;

        case MODUS_ENTSPERREN:
            // 2× alles orange aufblinken – blockierend, da Einmal-Effekt
            for (int i = 0; i < 2; i++) {
                fill_solid(leds, LED_NUM, CRGB(255, 120, 0));
                FastLED.show();
                delay(ENTSPERR_MS);
                _allesAus();
                delay(ENTSPERR_MS);
            }
            break;

        case MODUS_AMBIENTE:
            _allesAus();
            // Sanftes Blau über den ganzen Streifen
            _bereichFarbe(0, LED_NUM - 1, CRGB(0, 20, 80));
            FastLED.show();
            break;

        // Blinker-Modi werden in update() animiert
        case MODUS_BLINKER_LINKS:
        case MODUS_BLINKER_RECHTS:
            _allesAus();
            break;
    }
}


void LED::update() {
    if (_modus != MODUS_BLINKER_LINKS &&
        _modus != MODUS_BLINKER_RECHTS) return;

    uint32_t jetzt = millis();
    if (jetzt - _letzterBlink < BLINK_MS) return;

    _letzterBlink = jetzt;
    _blinkZustand = !_blinkZustand;

    _allesAus();

    if (_blinkZustand) {
        if (_modus == MODUS_BLINKER_LINKS) {
            // Linke Hälfte = erste 30 LEDs orange
            _bereichFarbe(0, 29, CRGB(255, 120, 0));
        } else {
            // Rechte Hälfte = letzte 30 LEDs orange
            _bereichFarbe(30, LED_NUM - 1, CRGB(255, 120, 0));
        }
    }
    FastLED.show();
}

// ─────────────────────────────────────────────
//  Private Hilfsfunktionen
// ─────────────────────────────────────────────
void LED::_allesAus() {
    fill_solid(leds, LED_NUM, CRGB(0, 0, 0));
    FastLED.show();
}

void LED::_bereichFarbe(uint8_t von, uint8_t bis, CRGB farbe) {
    for (uint8_t i = von; i <= bis; i++) {
        leds[i] = farbe;
    }
    // Kein show() hier – wird vom Aufrufer gemacht (Batching)
}