/*
IR-Empfangsmodul Ausleseprogramm für ESP32 S3
*/

#include <Arduino.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 21  // Anpassen an den tatsächlichen GPIO des IR-Empfängers

void setup() {
  Serial.begin(112500);  // UART0 
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR-Empfänger gestartet...");
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("HEX-Code: 0x");
    Serial.println(code, HEX);

    /* 
    //Beispiel für spezifische Codes
    if (code == 0xFA053000) {
      Serial.println("Hallo");
    }
    */

    IrReceiver.resume();  // Nächsten Code empfangen
  }
}
