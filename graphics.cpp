#include "graphics.h"

void startSequence(Adafruit_ILI9341 *tft) {
  tft->begin();
  tft->setRotation(1);

  //Initialize Screen
  tft->fillScreen(ILI9341_BLACK);
  tft->setCursor(0, 0);
  tft->setTextColor(AMBER);
  tft->setTextSize(2);
  tft->println("Initializing screen");

  //Set time
  tft->setCursor(0, 15);
  tft->println("Setting Time");

  tft->fillScreen(ILI9341_BLACK);
  tft->setCursor((tft->width()/2)-95, (tft->height()/2)-14);
  tft->println("Welcome to TanigOS");
  //delay(3000);
  tft->fillScreen(ILI9341_BLACK);
}

void drawMainScreen(Adafruit_ILI9341 *tft) {

  tft->drawRect(0, 0, tft->width(), 13, AMBER);
  tft->setCursor(2, 3);
  tft->setTextColor(AMBER);
  tft->setTextSize(1);

  tft->println("Jan 01 2000");
}