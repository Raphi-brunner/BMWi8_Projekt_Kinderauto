#include <Arduino.h>
#include "defines.h"
#include "LED.h"
#include "Buzzer.h"

LED led;
Buzzer buzzer(BUZZER);

// Variables für Buzzer-Timing
int letzterModus = -1;
unsigned long letztesPiepen = 0;

void setup()
{
    Serial0.begin(115200);
    Serial0.println("=== BMW i8 Kinderauto – Systemstart ===");

    led.begin();
    
    // Ganghebel Pins als INPUT_PULLDOWN (prüfen ob Hardware auf 3V3 gezogen wird)
    pinMode(G_VOR, INPUT_PULLDOWN);
    pinMode(G_RUEK, INPUT_PULLDOWN);

    Serial0.println("0=AUS");
    Serial0.println("1=FAHREN");
    Serial0.println("2=RUECKWAERTS");
}

void loop()
{
    int modus = MODUS_AMBIENTE; // Default

    if (digitalRead(G_VOR) == HIGH)
    {
        modus = MODUS_FAHREN;
    }
    else if (digitalRead(G_RUEK) == HIGH)
    {
        modus = MODUS_RUECKWAERTS;
    }
    else if (Serial0.available())
    {
        modus = Serial0.parseInt();
    }

    switch (modus)
    {
    case MODUS_AUS:
        Serial0.println("MODUS_AUS");
        led.setModus(MODUS_AUS);
        break;
    case MODUS_FAHREN:
        Serial0.println("MODUS_FAHREN");
        led.setModus(MODUS_FAHREN);
        break;
    case MODUS_RUECKWAERTS:
        Serial0.println("MODUS_RUECKWAERTS");
        led.setModus(MODUS_RUECKWAERTS);
        // Piepen alle 2 Sekunden im Rückwärts-Modus
        if (millis() - letztesPiepen >= 1000)
        {
            buzzer.playReverseTone();
            letztesPiepen = millis();
        }
        break;
    case MODUS_ENTSPERREN:
        Serial0.println("MODUS_ENTSPERREN");
        led.setModus(MODUS_ENTSPERREN);
        break;
    case MODUS_AMBIENTE:
        Serial0.println("MODUS_AMBIENTE");
        led.setModus(MODUS_AMBIENTE);
        break;
    case MODUS_BLINKER_LINKS:
        Serial0.println("MODUS_BLINKER_LINKS");
        led.setModus(MODUS_BLINKER_LINKS);
        break;
    case MODUS_BLINKER_RECHTS:
        Serial0.println("MODUS_BLINKER_RECHTS");
        led.setModus(MODUS_BLINKER_RECHTS);
        break;
    case MODUS_WARN:
        Serial0.println("MODUS_WARN");
        led.setModus(MODUS_WARN);
        break;
    default:
        Serial0.println("Ungueltiger Modus");
        break;
    }

    led.update();
}