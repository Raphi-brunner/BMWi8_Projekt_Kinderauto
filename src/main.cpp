#include <Arduino.h>
#include "defines.h"
#include "Motorsteuerung.h"
#include "JSN_SR04.h"
#include "IRHandler.h"
#include "Buzzer.h"
#include "BME280.h"
#include "LED.h"


MotorDriver motor1(AHI1, ALI1, BHI1, BLI1, DIS);
MotorDriver motor2(AHI2, ALI2, BHI2, BLI2, DIS);


IRHandler TabletIR(2);


Buzzer buzzer(BUZZER);


// Seite:  jsn_S_R = Seite Rechts  |  jsn_S_L = Seite Links
// Hinten: jsn_B_R1/R2 = hinten rechts außen/mittig  |  jsn_B_L1/L2 = hinten links außen/mittig
JSN_SR04 jsn_S_R (TRIG_PIN, ECHO_PIN_1, "Seite Rechts");
JSN_SR04 jsn_S_L (TRIG_PIN, ECHO_PIN_2, "Seite Links");
JSN_SR04 jsn_B_R1(TRIG_PIN, ECHO_PIN_3, "Heck Rechts 1");
JSN_SR04 jsn_B_L1(TRIG_PIN, ECHO_PIN_4, "Heck Links 1");
JSN_SR04 jsn_B_R2(TRIG_PIN, ECHO_PIN_5, "Heck Rechts 2");
JSN_SR04 jsn_B_L2(TRIG_PIN, ECHO_PIN_6, "Heck Links 2");


bool autoGestartet = false;


float minHeckDistanz() {
  float d1 = jsn_B_R1.measure();
  float d2 = jsn_B_L1.measure();
  float d3 = jsn_B_R2.measure();
  float d4 = jsn_B_L2.measure();

  float minDist = d1;
  if (d2 < minDist) minDist = d2;
  if (d3 < minDist) minDist = d3;
  if (d4 < minDist) minDist = d4;
  return minDist;
}

void setup() {
  Serial.begin(115200);
  Serial.println("=== BMW i8 Kinderauto – Systemstart ===");


  motor1.begin();
  motor2.begin();

  TabletIR.begin();

  jsn_S_R.begin();
  jsn_S_L.begin();
  jsn_B_R1.begin();
  jsn_B_L1.begin();
  jsn_B_R2.begin();
  jsn_B_L2.begin();

  pinMode(G_VOR,  INPUT_PULLDOWN);
  pinMode(G_RUEK, INPUT_PULLDOWN);

  buzzer.playUnlockTone();

  Serial.println("System bereit – warte auf IR-Entsperrung...");
}

void loop() {

  uint32_t irCode = TabletIR.receive();

  if (irCode == IR_ENTSPERREN) {
    if (!autoGestartet) {
      autoGestartet = true;
      buzzer.playUnlockTone();        
      Serial.println("Auto entsperrt!");

    }
  }

  if (!autoGestartet) return;

  float distHeck = minHeckDistanz();

  Serial.print("Heck-Distanz min: ");
  Serial.print(distHeck);
  Serial.println(" cm");

  bool ganVor  = digitalRead(G_VOR)  == HIGH;
  bool ganRuek = digitalRead(G_RUEK) == HIGH;

  if (ganVor && !ganRuek) {
    motor1.forward(SPEED_VOR);
    motor2.forward(SPEED_VOR);
    Serial.println("Fahre: VORWÄRTS");


  } else if (ganRuek && !ganVor) {
    motor1.backward(SPEED_RUEK);
    motor2.backward(SPEED_RUEK);
    Serial.println("Fahre: RÜCKWÄRTS");

    buzzer.playReverseTone(distHeck);


  } else {
    motor1.neutral();
    motor2.neutral();
    Serial.println("Status: NEUTRAL");

  }

  delay(50);
}