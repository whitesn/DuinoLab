#include <Arduino.h>

const int LED_PIN = 13;
const int WAKTU_KEDIP = 200; // milisecond

void setup() {
    pinMode( LED_PIN, OUTPUT );
}

void loop() {
    digitalWrite( LED_PIN, HIGH );
    delay( WAKTU_KEDIP );
    digitalWrite( LED_PIN, LOW );
    delay( WAKTU_KEDIP );
}
