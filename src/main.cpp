#include <Arduino.h>
#include "LED.h"
#include "Buzzer.h"

LED led;
Buzzer buzzer(BUZZER);

void setup() {
    Serial.begin(115200);
    led.begin();
}

void loop() {

    led.setModus(MODUS_BLINKER_LINKS);
    led.update();
    delay(BLINK_MS);
    led.setModus(MODUS_AUS);
    delay(BLINK_MS);
}