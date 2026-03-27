#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>

class MotorDriver {
  private:
    int _AHI;
    int _ALI;
    int _BHI;
    int _BLI;
    int _DIS;

    int pwmChannel;
    int pwmPin;

  public:
    MotorDriver(int AHI, int ALI, int BHI, int BLI, int DIS);

    void begin();
    void forward(int speed);
    void backward(int speed);
    void stop();
    void neutral();

};

#endif