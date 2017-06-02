#include <Arduino.h>

const int PIN_BUTTON = 11;
const int PIN_LED = 12;

bool led_on = false;
bool button_ready = true;

void setup() {
    pinMode( PIN_LED, OUTPUT );
    pinMode( PIN_BUTTON, INPUT_PULLUP );
}

void loop() {
    
    if( digitalRead(PIN_BUTTON) == LOW && button_ready ) {
        
        if( led_on ) {
            digitalWrite( PIN_LED, LOW );
            led_on = false;
        } else {
            digitalWrite( PIN_LED, HIGH );
            led_on = true;
        }
        
        button_ready = false;        
    } else if( digitalRead(PIN_BUTTON) == HIGH && !button_ready ) { 
        button_ready = true;      
    }
    
    delay( 10 );
}

