#include <Arduino.h>

const int PIN_IR_RECEIVER = 12;
const int PIN_RED = 3;
const int PIN_GREEN = 9;
const int PIN_BLUE = 10;

bool input_ready = true;

void setup() {
    
    pinMode( PIN_IR_RECEIVER, INPUT_PULLUP );
    pinMode( PIN_RED, OUTPUT );
    pinMode( PIN_GREEN, OUTPUT );
    pinMode( PIN_BLUE, OUTPUT );
    randomSeed( analogRead(0) );
}

void loop() {
    
    if( input_ready && digitalRead(PIN_IR_RECEIVER) == LOW ) {
        color_randomizer();
        input_ready = false;
    } else if( !input_ready && digitalRead(PIN_IR_RECEIVER) == HIGH ) {
        input_ready = true;
    }
}

void color_randomizer() {
    int red = random( 256 );
    int green = random( 256 );
    int blue = random( 256 );
    analogWrite( PIN_RED, red );
    analogWrite( PIN_GREEN, green );
    analogWrite( PIN_BLUE, blue );
}

