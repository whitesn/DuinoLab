#include <Arduino.h>

const int PIN_LED = 3;
const int PIN_TILT = 4;

const int MAX_BRIGHTNESS = 255;
int brightness = 0;

void setup() {
    pinMode( PIN_LED, OUTPUT );
    pinMode( PIN_TILT, INPUT_PULLUP );
}

void loop() {
    
    if( digitalRead(PIN_TILT) == LOW ) {
        brightness += (brightness < 255) ? 1 : 0;
    } else {
        brightness -= (brightness > 0) ? 1 : 0;
    }

    analogWrite( PIN_LED, MAX_BRIGHTNESS - brightness );
    delay( 10 );
}

