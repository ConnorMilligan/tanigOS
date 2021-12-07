#include "SPI.h" //Library Import
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

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
  tft.begin(); //Establishes SPI with TFT
  tft.setRotation(1); //Make the funny thing horizontal.
}

void loop(void) {
    testText();
    delay(15000); //Wait 15 seconds before rewriting.
}

unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK); //Wipe active LCD elements.
  tft.setCursor(0, 0); //Set virtual write cursor to upper left hand corner.
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.println("Test text");
}

//Note: LCD will flicker right now, when we get a battery setup the VCC of the LCD will hook directly into the regulated 3.3V output but currently power is shared between the processor and backlight for simplicity.