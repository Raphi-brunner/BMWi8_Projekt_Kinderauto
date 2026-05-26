#ifndef BME280_H
#define BME280_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Handler {
public:
    BME280Handler(uint8_t sdaPin, uint8_t sclPin, uint8_t adresse = 0x76);

    bool begin();

    float getTemperatur();
    float getLuftfeuchte();
    float getLuftdruck();
    void  printWerte();

private:
    uint8_t          _sdaPin;
    uint8_t          _sclPin;
    uint8_t          _adresse;
    Adafruit_BME280  _bme;
};

#endif