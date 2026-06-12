#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
private:
    int pin;  // Buzzer-Pin

public:
    Buzzer(int buzzerPin);  // Konstruktor
    void playReverseTone();  // Piept bei Hindernis (z.B. Rückwärtsfahren)
    void playUnlockTone();  // Kurzer Ton für Aufsperren
    void uploadTone();  // Ton für Hochladen
};

#endif