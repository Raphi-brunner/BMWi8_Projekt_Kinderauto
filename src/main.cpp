/*
Main für das Kinderauto BMW i8 Projekt
*/

#include <Arduino.h>
#include "IRHandler.h"


IRHandler ir(21); // 21 = Pin für IR-Empfang

void setup() {
  Serial.begin(115200);  
  ir.begin();
}

void loop() {
  ir.receive(); // IR-Signale empfangen und ausgeben aktuell: Konsole

}
  
