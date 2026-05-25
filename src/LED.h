#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <FastLED.h>

// LED Konfiguration
#define DATA_PIN 48
#define NUM_LEDS 5
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

class LED {
private:
    static CRGB leds[NUM_LEDS];
    static bool initialized;

public:
    // Initialisierung
    static void init();

    // Alle LEDs einschalten (weiß)
    static void all_on();

    // Alle LEDs ausschalten
    static void all_off();

    // Einzelne LED setzen (Index: 0-4, Farbe als CRGB)
    static void set_led(uint8_t index, CRGB color);

    // Alle LEDs auf eine Farbe setzen
    static void set_all_color(CRGB color);

    // Helligkeit einstellen (0-255)
    static void set_brightness(uint8_t brightness);

    // LED blinken
    static void blink(uint8_t index, uint16_t delay_ms);

    // Alle LEDs blinken
    static void blink_all(uint16_t delay_ms);

    // Farbverlauf (Regenbogeneffekt)
    static void rainbow(uint16_t delay_ms);

    // Update Display
    static void show();

    // Getters
    static bool is_initialized();
    static CRGB get_led(uint8_t index);
};

#endif
