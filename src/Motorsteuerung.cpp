#include "Motorsteuerung.h"

MotorDriver::MotorDriver(int AHI, int ALI, int BHI, int BLI, int DIS) : _AHI(AHI), _ALI(ALI), _BHI(BHI), _BLI(BLI), _DIS(DIS) {}

void MotorDriver::begin() {
  pinMode(_AHI, OUTPUT);
  pinMode(_ALI, OUTPUT);
  pinMode(_BHI, OUTPUT);
  pinMode(_BLI, OUTPUT);
  pinMode(_DIS, OUTPUT);

  // PWM einrichten
  ledcSetup(0, 20000, 8);    // Kanal 0, 20 kHz, 8 Bit
  ledcSetup(1, 20000, 8);    // Kanal 1, 20 kHz, 8 Bit

  ledcAttachPin(_ALI, 0);   // PWM ALI -> PWM Kanal 0
  ledcAttachPin(_BLI, 1);   // PWM BLI -> PWM Kanal 1

  digitalWrite(_DIS, HIGH); // Motoren deaktivieren (neutral)
}

void MotorDriver::forward(int speed) {
  // Stop vorher aktivieren, um Deadtime einzuhalten
  digitalWrite(_DIS, LOW); // Motoren freigeben
  stop();
  delayMicroseconds(2);  // Deadtime

  digitalWrite(_AHI, HIGH);
  digitalWrite(_BHI, LOW);
  ledcWrite(0, 0); //anderen PWM-Kanal auf LOW setzen, um sicherzustellen, dass nur einer aktiv ist
  ledcWrite(1, speed); // PWM Kanal 1 (_BLI) aktivieren
}

void MotorDriver::backward(int speed) {
  digitalWrite(_DIS, LOW); // Motoren freigeben
  stop();
  delayMicroseconds(2);  // Deadtime

  digitalWrite(_AHI, LOW);
  digitalWrite(_BHI, HIGH);
  ledcWrite(1, 0); //anderen PWM-Kanal auf LOW setzen, um sicherzustellen, dass nur einer aktiv ist
  ledcWrite(0, constrain(speed, 0, 170)); // PWM Kanal 0 (_ALI) beschränkt auf 170 (ca. 66% Leistung) für Rückwärtsfahrt.
}

void MotorDriver::stop() {
  ledcWrite(0, 0);
  ledcWrite(1, 0);

  digitalWrite(_AHI, LOW);
  digitalWrite(_ALI, LOW);
  digitalWrite(_BHI, LOW);
  digitalWrite(_BLI, LOW);
}

void MotorDriver::neutral() {
  digitalWrite(_DIS, HIGH); // Motoren deaktivieren (neutral)
}