#include "LED.h"
#include <Arduino.h>

CRGB leds[LED_NUM];

LED::LED()
    : _modus(MODUS_AUS),
      _blinkZustand(false),
      _letzterBlink(0) {}

void LED::begin()
{
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_NUM);
    FastLED.setBrightness(LED_HELLIGKEIT);
    _leds[0];
    _allesAus();
    Serial.println("LED-Streifen initialisiert (60 LEDs)");
}

void LED::setModus(uint8_t modus)
{
    _modus = modus;
    _blinkZustand = false;
    _letzterBlink = 0;

    Serial.print("LED Modus: ");
    Serial.println(modus);

    switch (_modus)
    {
    case MODUS_AUS:
        _allesAus();
        break;

    case MODUS_FAHREN:
        _allesAus();
        _bereichFarbe(FRONT_START, FRONT_END, CRGB(255, 255, 220));
        _bereichFarbe(HECK_START, HECK_END, CRGB(0, 255, 0));
        _chBright(HECK_START, HECK_END, 0);
        FastLED.show();
        break;

    case MODUS_RUECKWAERTS:
        _allesAus();
        _bereichFarbe(HECK_START, HECK_END, CRGB(0, 255, 0));
        _chBright(HECK_START, HECK_END, 1);
        _bereichFarbe(FRONT_START, FRONT_END, CRGB(255, 255, 220));
        FastLED.show();
        break;

    case MODUS_ENTSPERREN:
        for (int i = 0; i < 2; i++)
        {
        _bereichFarbe(FRONT_START, FRONT_END, CRGB(255, 255, 220));
        _bereichFarbe(HECK_START, HECK_END, CRGB(0, 255, 0));
        _bereichFarbe(MITTE_START, MITTE_END, CRGB(0, 20, 80));
        _chBright(HECK_START, HECK_END, 0);
            FastLED.show();
            delay(ENTSPERR_MS);
            _allesAus();
            delay(ENTSPERR_MS);
        }
        break;

    case MODUS_AMBIENTE:
        _allesAus();
        _bereichFarbe(MITTE_START, MITTE_END, CRGB(0, 20, 80));
        FastLED.show();
        break;
    
    case MODUS_WARN:
    case MODUS_BLINKER_LINKS:
    case MODUS_BLINKER_RECHTS:
        _allesAus();
        break;
    }
}

void LED::update()
{
    if (_modus != MODUS_BLINKER_LINKS &&
        _modus != MODUS_BLINKER_RECHTS && _modus != MODUS_WARN)
        return;
    
    uint32_t jetzt = millis();
    if (jetzt - _letzterBlink < BLINK_MS)
        return;

    _letzterBlink = jetzt;
    _blinkZustand = !_blinkZustand;

    _allesAus();

    if (_blinkZustand)
    {
        if (_modus == MODUS_BLINKER_LINKS)
        {
            _bereichFarbe(0, 5, CRGB(150, 255, 0));
            _bereichFarbe(17, 21, CRGB(255, 50, 0));
            _chBright(0, 5, 1);
            _chBright(17, 21, 1);

        }
        else if (_modus == MODUS_BLINKER_RECHTS)
        {
            _bereichFarbe(5, 1, CRGB(150, 255, 0));
            _bereichFarbe(11, 16, CRGB(255, 50, 0)); 
            _chBright(5, 16, 1);
        }
        else if (_modus == MODUS_WARN)
        {
            _bereichFarbe(0, 5, CRGB(150, 255, 0));
            _bereichFarbe(17, 21, CRGB(255, 50, 0));
            _bereichFarbe(5, 1, CRGB(150, 255, 0));
            _bereichFarbe(11, 16, CRGB(255, 50, 0)); 
            _chBright(FRONT_START, HECK_END, 1);
        }
    }
    FastLED.show();
}

//Hilfsfuntkionen
void LED::_allesAus()
{
    fill_solid(leds, LED_NUM, CRGB(0, 0, 0));
    FastLED.show();
}

void LED::_bereichFarbe(uint8_t von, uint8_t bis, CRGB farbe)
{
    for (uint8_t i = von; i <= bis; i++)
    {
        leds[i] = farbe;
    }
}

void LED::_chBright(uint8_t von, uint8_t bis, bool mode){
        for (int i = von; i <= bis; i++)
        {
            if(mode == 1)
            leds[i].nscale8(HIGH_BRIGHTNESS);
            else if(mode == 0)
            leds[i].nscale8(DIM_BRIGHTNESS);
        }
}