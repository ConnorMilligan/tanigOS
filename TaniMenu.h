#ifndef TANIGOS_MENU
#define TANIGOS_MENU

#include "Adafruit_ILI9341.h"
#include "graphics.h"
#include <vector>

#define TEXT_SPACING 18

struct menuData
{
    int x;
    int y;
    int width;
    int height;
};


class TaniMenu {
private:
    Adafruit_ILI9341 *screen;
    menuData info;
    std::vector<String> choices;
    int selection;
public:
    TaniMenu();
    TaniMenu(Adafruit_ILI9341 *screen, menuData info, std::vector<String> choices);

    void draw();
    void cursorUp();
    void cursorDown();
};


#endif