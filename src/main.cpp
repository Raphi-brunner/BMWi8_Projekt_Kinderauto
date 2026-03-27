#include <Arduino.h>
#include "Motorsteuerung.h"
#include "JSN_SR04.h"
#include "IRHandler.h"
#include "defines.h"

// Motoren initialisieren
MotorDriver motor1(AHI1, ALI1, BHI1, BLI1, DIS1);
MotorDriver motor2(AHI2, ALI2, BHI2, BLI2, DIS2);

// IR-Empfänger initialisieren
IRHandler TabletIR(2); // Beispiel: Pin 2 für IR-Empfänger

/*
// Ultraschallsensoren initialisieren
// 2. Sensor hinten rechts oder links mittig - 1. sind die hinten außen - R und L sind die Seiten
JSN_SR04 jsn_S_R(TRIG_PIN, ECHO_PIN_1);
JSN_SR04 jsn_S_L(TRIG_PIN, ECHO_PIN_2);
JSN_SR04 jsn_B_R1(TRIG_PIN, ECHO_PIN_3);
JSN_SR04 jsn_B_L1(TRIG_PIN, ECHO_PIN_4);
JSN_SR04 jsn_B_R2(TRIG_PIN, ECHO_PIN_5); 
JSN_SR04 jsn_B_L2(TRIG_PIN, ECHO_PIN_6);
*/

void setup() {
  Serial.begin(115200);

  // Motoren starten
  motor1.begin();
  motor2.begin();
  TabletIR.begin();

  pinMode(G_VOR, INPUT_PULLDOWN);
  pinMode(G_RUEK, INPUT_PULLDOWN);

  Serial.println("Kinderauto startet: vorwärts fahren");
}

void loop() {

if (TabletIR.receive() == 0xFF629D) {   // Überprüfen ob Auto gestartet wurde "0xFF629D" Beispiel
  /*
  LICHT und Sonstiges hier einfügen,
  */
  
  if (digitalRead(G_VOR) == HIGH) {   
    
  }
  else if (digitalRead(G_RUEK) == HIGH) {

  }
  else if (digitalRead(G_RUEK) == LOW && digitalRead(G_VOR) == LOW) {
    motor1.neutral();
  }
  
};
  int speed = 100; // Geschwindigkeit 0-255
  motor1.forward(speed);
 

  // Kein Stop, fährt kontinuierlich vorwärts
  delay(100); // kleine Pause, damit loop nicht komplett durchrauscht
}