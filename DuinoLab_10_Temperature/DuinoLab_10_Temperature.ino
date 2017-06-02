#include <Arduino.h>

#include <dht.h>

const int DHT11_PIN = A0;
dht DHT;

void setup() {
    Serial.begin( 9600 );
    Serial.println("Status\tKelembaban (%)\tTemperatur(C)");
}

void loop() {
    
    int chk = DHT.read11( DHT11_PIN );

    switch(chk) {
    case DHTLIB_OK:  
        Serial.print("OK,\t"); 
        break;
    case DHTLIB_ERROR_CHECKSUM: 
        Serial.print("Checksum error,\t"); 
        break;
    case DHTLIB_ERROR_TIMEOUT: 
        Serial.print("Time out error,\t"); 
        break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
        Serial.print("Unknown error,\t"); 
        break;
    }

    Serial.print( DHT.humidity );
    Serial.print("\t\t");
    Serial.println( DHT.temperature );

    delay( 2000 );
}
       

