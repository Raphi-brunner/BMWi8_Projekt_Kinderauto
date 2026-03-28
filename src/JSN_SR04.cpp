#include "JSN_SR04.h"
#include <Arduino.h>

JSN_SR04::JSN_SR04(uint8_t TRIG, uint8_t ECHO) : _TRIG(TRIG), _ECHO(ECHO) {}

void JSN_SR04::begin() {
    pinMode(_TRIG, OUTPUT);
    digitalWrite(_TRIG, LOW);

    pinMode(_ECHO, INPUT);
}


float JSN_SR04::distance() {
  // Trigger Impuls 20 µs
  digitalWrite(_TRIG, HIGH);
  delayMicroseconds(20);
  digitalWrite(_TRIG, LOW);

  // Echo messen
  echoZeit = pulseIn(_ECHO, HIGH, 30000); // Timeout 30 ms (~5 m)

  /*if (echoZeit == 0) {
    Serial0.println("Kein Echo (Objekt zu nah oder zu weit)");
  } else {
    // Entfernung in cm berechnen
    distanz = (echoZeit * 0.0343) / 2.0;

    if (distanz < 25.0) {
      Serial0.println("Objekt zu nah (<25 cm, Totzone JSN-SR04T)");
    } else {
      Serial0.print("Entfernung: ");
      Serial0.print(distanz);
      Serial0.println(" cm");
    }
  }*/

  distanz = (echoZeit * 0.0343) / 2.0; // Entfernung in cm berechnen
  return distanz;

}
