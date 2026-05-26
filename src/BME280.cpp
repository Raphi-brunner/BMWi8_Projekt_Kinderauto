#include "BME280.h"
#include <Arduino.h>

BME280Handler::BME280Handler(uint8_t sdaPin, uint8_t sclPin, uint8_t adresse)
    : _sdaPin(sdaPin), _sclPin(sclPin), _adresse(adresse) {}

bool BME280Handler::begin() {
    Wire.begin(_sdaPin, _sclPin);
    if (!_bme.begin(_adresse)) {
        Serial.println("BME280 nicht gefunden!");
        return false;
    }
    Serial.println("BME280 erfolgreich gestartet!");
    return true;
}

float BME280Handler::getTemperatur() {
    return _bme.readTemperature();
}

float BME280Handler::getLuftfeuchte() {
    return _bme.readHumidity();
}

float BME280Handler::getLuftdruck() {
    return _bme.readPressure() / 100.0F;
}

void BME280Handler::printWerte() {
    Serial.println("===== BME280 Werte =====");
    Serial.print("Temperatur: ");
    Serial.print(getTemperatur());
    Serial.println(" °C");
    Serial.print("Luftfeuchte: ");
    Serial.print(getLuftfeuchte());
    Serial.println(" %");
    Serial.print("Luftdruck: ");
    Serial.print(getLuftdruck());
    Serial.println(" hPa");
    Serial.println();
}