#include <Arduino.h>

#include <LiquidCrystal.h>
#include <DS3231.h>

const int PIN_RS = 2;
const int PIN_E = 3;
const int PIN_D4 = 4;
const int PIN_D5 = 5;
const int PIN_D6 = 6;
const int PIN_D7 = 7;

const String REQ_ADJUST_TIME = "ADJTIME";
const String TIME_ADJUST_STRING[] = { "jam", "menit", "detik", "tanggal", "bulan", "tahun" };
const int TIME_BOTTOM_THRESHOLD[] = { 0, 0, 0, 1, 1, 2000 };
const int TIME_UPPER_THRESHOLD[] = { 23, 59, 59, 31, 12, 2099 };

LiquidCrystal lcd( PIN_RS, PIN_E, PIN_D4, PIN_D5, PIN_D6, PIN_D7 );
DS3231 rtc(SDA, SCL);

void setup()
{
   lcd.begin(16,2);
   rtc.begin();
   Serial.begin(9600);
}

void loop()
{
   if( Serial.available() ) {
      String recv = Serial.readString();
      if( recv == "ADJTIME" ) {
         adjust_time();
      }
   }

   update_lcd();
   delay( 100 );
}

void adjust_time() 
{
   int waktu[6];
   
   for( int i = 0; i < 6; i++ ) {
      String dialog = "Input " + TIME_ADJUST_STRING[i] + " (" + 
                      String(TIME_BOTTOM_THRESHOLD[i]) + "~" + 
                      String(TIME_UPPER_THRESHOLD[i]) + ") : ";
      Serial.print( dialog );
      
      while(true) {
         while(!Serial.available()) {
            update_lcd();
         }
      
         int recv = Serial.parseInt();
         if( recv < TIME_BOTTOM_THRESHOLD[i] || recv > TIME_UPPER_THRESHOLD[i] ) {
            Serial.println("[ERROR]: Cek kembali input waktu");
         } else {
            waktu[i] = recv;
            break;
         }
      }
   }

   rtc.setTime( waktu[0], waktu[1], waktu[2] );
   rtc.setDate( waktu[3], waktu[4], waktu[5] );
}

void update_lcd() 
{
   Serial.println("Updating...");
   //lcd.clear();
   String test = rtc.getTimeStr(FORMAT_LONG);
   Serial.println( test );
   //lcd.print(  );
   Serial.println("Updating2...");
   lcd.setCursor( 0, 1 );
   lcd.print( rtc.getDateStr(FORMAT_LONG,FORMAT_BIGENDIAN,'-') );

   Serial.println("Updated lcd...");
}

