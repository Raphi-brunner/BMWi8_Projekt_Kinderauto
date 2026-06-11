#include <Arduino.h>
#include "defines.h"
#include "Motorsteuerung.h"
#include "JSN_SR04.h"
#include "IRHandler.h"
#include "Buzzer.h"
#include "BME280.h"
#include "LED.h"

LED led;
Buzzer buzzer(BUZZER);

void setup()
{
    Serial0.begin(115200);
    Serial0.println("=== BMW i8 Kinderauto – Systemstart ===");

    led.begin();
    // buzzer.uploadTone();

    Serial0.println("0=AUS");
    Serial0.println("1=FAHREN");
    Serial0.println("2=RUECKWAERTS");
    Serial0.println("3=ENTSPERREN");
    Serial0.println("4=AMBIENTE");
    Serial0.println("5=BLINKER_LINKS");
    Serial0.println("6=BLINKER_RECHTS");
    Serial0.println("7=WARNBLINKEINRICHTUNG");
}

void loop()
{
    if (Serial0.available())
    {
        int modus = Serial0.parseInt();

        switch (modus)
        {
        case 0:
            Serial0.println("MODUS_AUS");
            led.setModus(MODUS_AUS);
            break;

        case 1:
            Serial0.println("MODUS_FAHREN");
            led.setModus(MODUS_FAHREN);
            break;

        case 2:
            Serial0.println("MODUS_RUECKWAERTS");
            led.setModus(MODUS_RUECKWAERTS);
            break;

        case 3:
            Serial0.println("MODUS_ENTSPERREN");
            led.setModus(MODUS_ENTSPERREN);
            break;

        case 4:
            Serial0.println("MODUS_AMBIENTE");
            led.setModus(MODUS_AMBIENTE);
            break;

        case 5:
            Serial0.println("MODUS_BLINKER_LINKS");
            led.setModus(MODUS_BLINKER_LINKS);
            break;

        case 6:
            Serial0.println("MODUS_BLINKER_RECHTS");
            led.setModus(MODUS_BLINKER_RECHTS);
            break;
        case 7:
            Serial0.println("MODUS_WARN");
            led.setModus(MODUS_WARN);
            break;

        default:
            Serial0.println("Ungueltiger Modus");
            break;
        }
    }

    led.update();
}