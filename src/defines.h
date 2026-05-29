#ifndef DEFINES_H
#define DEFINES_H


// Temperatur Sensor Pin
#define TEMP_PIN 3

// JSN-SR04 Trigger Pin
#define TRIG_PIN 5

// Buzzer Pin
#define BUZZER 4 

// JSN-SR04 Echo Pins
#define ECHO_PIN_1 9
#define ECHO_PIN_2 10
#define ECHO_PIN_3 11
#define ECHO_PIN_4 12 
#define ECHO_PIN_5 13
#define ECHO_PIN_6 14


// Motorsteuerung Pins
#define AHI1 35
#define ALI1 36
#define BHI1 37
#define BLI1 38
#define AHI2 39
#define ALI2 40
#define BHI2 41
#define BLI2 42

// Motor-Disable Pin
#define DIS 45

// Gangschaltungsen Pins INPUT
#define G_VOR 21
#define G_RUEK 47
 
//LED Pin, Anzahl und Helligkeit
#define LED_PIN      48   // GPIO-Pin → anpassen!
#define LED_NUM      48   // Anzahl LEDs
#define LED_HELLIGKEIT 150 // 0–255
#define DIM_BRIGHTNESS 50 // Helligkeit für Ambiente-Modus (0–255)
#define HIGH_BRIGHTNESS 255 // Helligkeit für Blinker-Modi (0–255)

//  LED-Bereiche auf dem Streifen
//  Streifen: [0..14] Front | [15..44] Mitte | [45..59] Heck
#define FRONT_START   0
#define FRONT_END     11   // 15 LEDs vorne
#define HECK_START    12
#define HECK_END      21   // 15 LEDs hinten
#define MITTE_START   22
#define MITTE_END     48
// Mitte (15–44) = Innenbeleuchtung / Ambiente


//  Licht-Modi
#define MODUS_AUS               0
#define MODUS_FAHREN            1  // Scheinwerfer weiß + Rücklicht rot
#define MODUS_RUECKWAERTS       2  // Rückfahrlicht weiß hinten
#define MODUS_BLINKER_LINKS     3  // Linke Hälfte orange blinkt
#define MODUS_BLINKER_RECHTS    4  // Rechte Hälfte orange blinkt
#define MODUS_ENTSPERREN        5  // 2× alles orange aufblinken
#define MODUS_AMBIENTE          6  // Sanftes blaues Innenlicht

//  Timing
#define BLINK_MS        700
#define ENTSPERR_MS     250

//  Schwellwerte Ultraschall
#define DIST_WARN_CM    25.0f   // Buzzer warnt ab dieser Distanz
#define DIST_CLOSE_CM   10.0f   // schnelles Piepen ab dieser Distanz


//  IR-Codes (Tablet-Fernbedienung)
#define IR_ENTSPERREN   0xFF629D  // Startet das Auto

//  Geschwindigkeit  (0–255 PWM)
#define SPEED_VOR   200   // Vorwärts-Geschwindigkeit
#define SPEED_RUEK  150   // Rückwärts-Geschwindigkeit (max. 170 hardwareseitig)

#endif

