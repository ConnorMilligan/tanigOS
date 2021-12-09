#ifndef TANIGOS_GRAPHICS
#define TANIGOS_GRAPHICS

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define AMBER 0xfd40

#define TFT_DC 0 //Pin definitions
#define TFT_CS 1
#define TFT_MOSI 3
#define TFT_CLK 2
#define TFT_RST 28
#define TFT_MISO 29
#define TFT_LED 27

#define KNOB_PINA 6
#define KNOB_PINB 7

void startSequence(Adafruit_ILI9341 *tft);

void drawMainScreen(Adafruit_ILI9341 *tft);

#endif