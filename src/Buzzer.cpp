#include "Buzzer.h"
#include "defines.h"

Buzzer::Buzzer(int buzzerPin) : pin(buzzerPin) {
    pinMode(pin, OUTPUT);
}

void Buzzer::playReverseTone(float distance) {
    if (distance < 25.0 && distance > 0) {  // Wenn ein Objekt zu nah ist
        tone(pin, 1000);  // Kontinuierlicher Ton bei 1000 Hz
    } 
    else if (distance < 10.0) {  // Wenn ein Objekt in mittlerer Entfernung ist
        tone(pin, 1500);  // Kontinuierlicher Ton bei 500 Hz
    }
    else {
        noTone(pin);  // Ton ausschalten
    }
}

void Buzzer::playUnlockTone() {
    tone(pin, 1500, 500);  // Kurzer Ton bei 1500 Hz für 500ms
}