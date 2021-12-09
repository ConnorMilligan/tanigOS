#include "SPI.h" //Library Import

#include "TaniMenu.h"
#include "graphics.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
TaniMenu newMenu(&tft, {0, 14, tft.width(), tft.height()-14}, {"Test1", "Test2", "Test3"});

 int encoderPosCount = 0;
 int pinALast;
 int aVal;
 boolean bCW;

void setup() {
  Serial.begin(9600); //Serial for debugging stuff etc.
  pinMode(TFT_LED, OUTPUT); //Backlight LED written to high for visibility of text.
  pinMode(KNOB_PINA, INPUT);
  pinMode(KNOB_PINB, INPUT);
  digitalWrite (TFT_LED, HIGH);
  startSequence(&tft);
  
}

void loop(void) {
  drawMainScreen(&tft);
  newMenu.draw();

  aVal = digitalRead(KNOB_PINA);
  if (aVal != pinALast){ // Means the knob is rotating
    // if the knob is rotating, we need to determine direction
    // We do that by reading pin B.
    if (digitalRead(KNOB_PINB) != aVal) { // Means pin A Changed first - We're Rotating Clockwise
      encoderPosCount ++;
      bCW = true;
    } else {// Otherwise B changed first and we're moving CCW
      bCW = false;
      encoderPosCount--;
    }
    if (bCW){
      newMenu.cursorUp();
    }else{
      newMenu.cursorDown();
    }
  }
  pinALast = aVal;


  delay(500); //Wait 15 seconds before rewriting.
}

//Note: LCD will flicker right now, when we get a battery setup the VCC of the LCD will hook directly into the regulated 3.3V output but currently power is shared between the processor and backlight for simplicity.