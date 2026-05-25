#include "LED.h"

// Statische Membervariablen initialisieren
CRGB LED::leds[NUM_LEDS];
bool LED::initialized = false;

void LED::init() {
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(200);  // Standardhelligkeit 200/255
    LED::all_off();
    initialized = true;
    Serial.println("[LED] Initialisiert - 5 LEDs an Pin 47");
}

void LED::all_on() {
    if (!initialized) return;
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::White;
    }
    show();
    Serial.println("[LED] Alle LEDs weiß AN");
}

void LED::all_off() {
    if (!initialized) return;
    FastLED.clear();
    show();
    Serial.println("[LED] Alle LEDs AUS");
}

void LED::set_led(uint8_t index, CRGB color) {
    if (!initialized || index >= NUM_LEDS) return;
    leds[index] = color;
    show();
    Serial.printf("[LED] LED %d gesetzt\n", index);
}

void LED::set_all_color(CRGB color) {
    if (!initialized) return;
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }
    show();
    Serial.println("[LED] Alle LEDs auf Farbe gesetzt");
}

void LED::set_brightness(uint8_t brightness) {
    if (!initialized) return;
    FastLED.setBrightness(brightness);
    show();
    Serial.printf("[LED] Helligkeit auf %d gesetzt\n", brightness);
}

void LED::blink(uint8_t index, uint16_t delay_ms) {
    if (!initialized || index >= NUM_LEDS) return;
    
    leds[index] = CRGB::White;
    show();
    delay(delay_ms);
    
    leds[index] = CRGB::Black;
    show();
    delay(delay_ms);
    
    Serial.printf("[LED] LED %d geblinkt\n", index);
}

void LED::blink_all(uint16_t delay_ms) {
    if (!initialized) return;
    
    all_on();
    delay(delay_ms);
    
    all_off();
    delay(delay_ms);
    
    Serial.println("[LED] Alle LEDs geblinkt");
}

void LED::rainbow(uint16_t delay_ms) {
    if (!initialized) return;
    
    CRGB colors[] = {
        CRGB::Red,
        CRGB::Yellow,
        CRGB::Green,
        CRGB::Cyan,
        CRGB::Blue
    };
    
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = colors[i % 5];
    }
    show();
    delay(delay_ms);
}

void LED::show() {
    if (!initialized) return;
    FastLED.show();
}

bool LED::is_initialized() {
    return initialized;
}

CRGB LED::get_led(uint8_t index) {
    if (index < NUM_LEDS) {
        return leds[index];
    }
    return CRGB::Black;
}
