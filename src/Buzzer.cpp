#include <Arduino.h>
#include "JSN_SR04.h"
#include "defines.h"

void Buzzer(){
    for (int i = 0; i < 6; i++) {
        JSN_SR04 sensor(TRIG_PIN, ECHO_PIN_1 + i); // Alle 6 Sensoren durchgehen
        sensor.begin();

        if (sensor.distance() < 25.0 && sensor.distance() > 0) { // Wenn ein Objekt zu nah ist (und kein Fehler vorliegt)
            do{
            tone(BUZZER, 1000); // Ton mit 1000 Hz erzeugen
            } while (sensor.distance() < 25.0 && sensor.distance() > 0); // Solange das Objekt zu nah ist, Ton beibehalten
        } else {
            noTone(BUZZER); // Ton ausschalten
        }
    }
};