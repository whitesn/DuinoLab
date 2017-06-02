#include <Arduino.h>

const int POT_PIN = A0;
const int LED_PIN = 11;

void setup() {
    pinMode( POT_PIN, INPUT );
    pinMode( LED_PIN, OUTPUT );
}

void loop() {
    int val = analogRead( POT_PIN ); // {0,1023}
    val = map( val, 0, 1023, 0 , 255 );
    analogWrite( LED_PIN, val );
}
