#include <Arduino.h>

const int PIN_MERAH = 11;
const int PIN_KUNING = 10;
const int PIN_HIJAU = 9;

const int DURASI_MERAH = 10; // detik
const int DURASI_KUNING = 2; // detik
const int DURASI_HIJAU = 8; // detik

void setup() {
    pinMode( PIN_MERAH, OUTPUT );
    pinMode( PIN_KUNING, OUTPUT );
    pinMode( PIN_HIJAU, OUTPUT );
}

void loop() {
    digitalWrite( PIN_MERAH, HIGH ); // nyalakan lampu merah
    delay( DURASI_MERAH * 1000 ); // 1 detik = 1000ms
    digitalWrite( PIN_MERAH, LOW ); // matikan lampu merah
    digitalWrite( PIN_KUNING, HIGH ); // nyalakan lampu kuning
    delay( DURASI_KUNING * 1000 ); // pause 2 detik
    digitalWrite( PIN_KUNING, LOW ); // matikan lampu kuning
    digitalWrite( PIN_HIJAU, HIGH ); // nyalakan lampu hijau
    delay( DURASI_HIJAU * 1000 ); // pause 8 detik
    digitalWrite( PIN_HIJAU, LOW ); // matikan lampu hijau
}

