#include "Buzzer.h"
#include "defines.h"

Buzzer::Buzzer(int buzzerPin) : pin(buzzerPin) {
    pinMode(pin, OUTPUT);
}

void Buzzer::playReverseTone() {
    tone(pin, 1000, 200);  // 1000 Hz für 200ms
}

void Buzzer::playUnlockTone() {
    tone(pin, 700, 100);  // Kurzer Ton bei 700 Hz für 500ms
    delay(10);  // Kurze Pause zwischen den Tönen
    tone(pin, 700, 100);  // Kurzer Ton bei 700 Hz für 500ms
}

void Buzzer::uploadTone() {
    tone(pin, 700);  // Kurzer Ton bei 700 Hz für 500ms
    delay(200);  // Warte 500ms
    noTone(pin);  // Ton ausschalten nach dem Abspielen
}