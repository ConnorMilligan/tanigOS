#include "SPI.h" //Library Import

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <ctime>

#define AMBER 0xfd40

#define TFT_DC 0 //Pin definitions
#define TFT_CS 1
#define TFT_MOSI 3
#define TFT_CLK 2
#define TFT_RST 28
#define TFT_MISO 29
#define TFT_LED 27

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
  Serial.begin(9600); //Serial for debugging stuff etc.
  pinMode(TFT_LED, OUTPUT); //Backlight LED written to high for visibility of text.
  digitalWrite (TFT_LED, HIGH);
  startSequence();
}

void loop(void) {
    drawMainScreen();
    delay(15000); //Wait 15 seconds before rewriting.
}

void startSequence() {
  tft.begin();
  tft.setRotation(1);

  //Initialize Screen
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(AMBER);
  tft.setTextSize(2);
  tft.println("Initializing screen");

  //Set time
  tft.setCursor(0, 0);
  tft.println("Setting Time");

  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor((tft.width()/2)-95, (tft.height()/2)-14);
  tft.println("Welcome to TanigOS");
  //delay(3000);
  tft.fillScreen(ILI9341_BLACK);
}

void drawMainScreen() {

  tft.drawRect(0, 0, tft.width(), 10, AMBER);
  tft.setCursor(0, 0);
  tft.setTextColor(AMBER);
  tft.setTextSize(1);

  tft.println("Jan 01 2000");
}

//Note: LCD will flicker right now, when we get a battery setup the VCC of the LCD will hook directly into the regulated 3.3V output but currently power is shared between the processor and backlight for simplicity.