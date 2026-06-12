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

// Motor-Disable Pin ?
#define DISABLE 46

// Gangschaltungsen Pins INPUT
#define G_VOR 47
#define G_RUEK 21
 
//LED Pin, Anzahl und Helligkeit
#define LED_PIN      48   
#define LED_NUM      48   
#define LED_HELLIGKEIT 150 // 0–255
#define DIM_BRIGHTNESS 50 
#define HIGH_BRIGHTNESS 255 

//  LED-Bereiche auf dem Streifen
#define FRONT_START   0
#define FRONT_END     11   
#define HECK_START    12
#define HECK_END      21   
#define MITTE_START   22
#define MITTE_END     48


//  Licht-Modi
#define MODUS_AUS               0
#define MODUS_FAHREN            1  
#define MODUS_RUECKWAERTS       2  
#define MODUS_BLINKER_LINKS     3  
#define MODUS_BLINKER_RECHTS    4  
#define MODUS_ENTSPERREN        5  
#define MODUS_AMBIENTE          6  
#define MODUS_WARN              7

//  Timing
#define BLINK_MS        400
#define ENTSPERR_MS     250

//Schwellwerte Ultraschall
#define DIST_WARN_CM    25.0f   // Buzzer warnt ab dieser Distanz
#define DIST_CLOSE_CM   10.0f   // schnelles Piepen ab dieser Distanz


//  IR-Codes (Tablet-Fernbedienung)
#define IR_ENTSPERREN   0xFF629D  // Startet das Auto

//  Geschwindigkeit  (0–255 PWM)
#define SPEED_VOR   200   // Vorwärts-Geschwindigkeit
#define SPEED_RUEK  150   // Rückwärts-Geschwindigkeit

#endif

