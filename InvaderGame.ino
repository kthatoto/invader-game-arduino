
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

#include "ascii.h"

#define PIN_SCE   12 //pin GPIO12 ON ESP , pin SCE ON LCD
#define PIN_RESET 2 //pin GPI02 on ESP , pin RST on LCD
#define PIN_DC    16 //pin GPIO14 on ESP , pin DC on LCD
#define PIN_SDIN  4 //pin GPIO4 on ESP , pin SDIN on LCD
#define PIN_SCLK  5 //pin GPIO5 on ESP  , pin SLCK on LCD

#define PIN_RIGHT  13
#define PIN_LEFT   14
#define PIN_OK     0

//The DC pin tells the LCD if we are sending a command or data
#define LCD_COMMAND 0 
#define LCD_DATA    1

//You may find a different size screen, but this one is 84 by 48 pixels
#define LCD_X     84
#define LCD_Y     48

#include "LCD.h"

#include "Invader.h"

int str_x = LCD_X/2;
int invaders_x[] = {10, 20, 30};
int invaders_y[] = {0, 1, 2};
int invaders_direct[] = {5, 5, 5};

Invader inv = Invader(10, 0, 5);

void setup() {
  LCDInit(); //Init the LCD
  LCDClear();
}

void loop() {
  LCDClear();

  inv.update();

  if (!digitalRead(PIN_RIGHT)) {
    str_x+=5;
  }
  if (!digitalRead(PIN_LEFT)) {
    str_x-=5;
  }
  gotoXY(str_x, 4);
  LCDString("u");

  delay(300);
}


