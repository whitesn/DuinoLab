#include <Arduino.h>

const int DATA_PIN  = 8;
const int LATCH_PIN = 9;
const int CLOCK_PIN = 10;

void setup() {
    pinMode( DATA_PIN, OUTPUT );
    pinMode( LATCH_PIN, OUTPUT );
    pinMode( CLOCK_PIN, OUTPUT );
}

void loop() {
    for( int i = 0; i < 8; i++ ) {
        byte leds = 0;
        bitSet( leds, i );
        digitalWrite( LATCH_PIN, LOW );
        
        for( int j = 0; j < 8; j++ ) {
            digitalWrite( DATA_PIN, leds & (1 << j) );
            digitalWrite( CLOCK_PIN, LOW );
            digitalWrite( CLOCK_PIN, HIGH );
        }
        
        digitalWrite( LATCH_PIN, HIGH );
        delay( 200 );
    }
}
