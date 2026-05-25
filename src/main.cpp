// main.cpp
#include <Arduino.h>
#include "JSN_SR04.h"
#include "defines.h"
#include "Buzzer.h"

Buzzer buzzer(BUZZER);

Sensor s1(TRIG_PIN, ECHO_PIN_1, "Sensor 1");
Sensor s2(TRIG_PIN, ECHO_PIN_2, "Sensor 2");
Sensor s3(TRIG_PIN, ECHO_PIN_3, "Sensor 3");
Sensor s4(TRIG_PIN, ECHO_PIN_4, "Sensor 4");
Sensor s5(TRIG_PIN, ECHO_PIN_5, "Sensor 5");
Sensor s6(TRIG_PIN, ECHO_PIN_6, "Sensor 6");

Sensor* sensors[] = {&s1, &s2, &s3, &s4, &s5, &s6};
int active_sensor = -1;
bool reverse_mode = false;

void printMenu() {
    Serial0.println("\n=== MENU ===");
    for (int i = 0; i < 6; i++) {
        Serial0.print(i + 1);
        Serial0.print(" = Sensor ");
        Serial0.println(i + 1);
    }
    Serial0.println("r = Rückwärtsmodus");
}

void handleReverseMode() {
    int order[] = {0, 1, 2, 5}; // Sensor 1,2,3,6
    float min_dist = 9999;
    int min_sensor = -1;

    for (int i = 0; i < 4; i++) {
        float d = sensors[order[i]]->measure();
        if (d > 0 && d < 100.0) {
            if (d < min_dist) {
                min_dist = d;
                min_sensor = order[i];
            }
        }
        delay(30);
    }

    if (min_sensor >= 0) {
        Serial0.print("Sensor ");
        Serial0.print(min_sensor + 1);
        Serial0.print(": ");
        Serial0.print(min_dist, 1);
        Serial0.println("cm");
        buzzer.playReverseTone(min_dist);
    }
}

void setup() {
    Serial0.begin(115200);
    delay(500);
    buzzer.playUnlockTone();
    for (int i = 0; i < 6; i++)
        sensors[i]->begin();
    printMenu();
}

void loop() {
    if (Serial0.available()) {
        char cmd = Serial0.read();

        if (cmd == 'r' || cmd == 'R') {
            reverse_mode = true;
            active_sensor = -1;
            Serial0.println("\n>>> RÜCKWÄRTSMODUS AKTIV <<<\n");
        } else if (cmd >= '1' && cmd <= '6') {
            reverse_mode = false;
            active_sensor = cmd - '1';
            Serial0.print("\n>>> Sensor ");
            Serial0.print(active_sensor + 1);
            Serial0.println(" AKTIV <<<\n");
        }
    }

    if (reverse_mode) {
        handleReverseMode();
    } else if (active_sensor >= 0) {
        float value = sensors[active_sensor]->measure();
        if (value > 0)
            Serial0.println(value, 1);
        else
            Serial0.println("---");
        delay(500);
    }
}