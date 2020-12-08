#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Firmata.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
int lastLine = 1;

void stringDataCallback(char *stringData){
   if ( lastLine ) {
     lastLine = 0;
     lcd.clear();
   } else {
     lastLine = 1;
     lcd.setCursor(0,1);
   }
   lcd.print(stringData);
}

void setup(){
	// initialize the LCD
	lcd.begin();

	Firmata.setFirmwareVersion( FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION );
  Firmata.attach( STRING_DATA, stringDataCallback);
  Firmata.begin();
}

void loop() {
  while ( Firmata.available() ) {
    Firmata.processInput();
  }
}
