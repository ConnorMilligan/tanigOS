#include "TaniMenu.h"

TaniMenu::TaniMenu() {
    this->screen = nullptr;
    this->choices = {};
    this->selection = 0;
}

TaniMenu::TaniMenu(Adafruit_ILI9341 *screen, menuData info, std::vector<String> choices) {
    this->screen = screen;
    this->info = info;
    this->choices = choices;
    this->selection = 0;
}

void TaniMenu::draw() {
    this->screen->drawRect(info.x, info.y, info.width, info.height, AMBER);
    int x = 4, y = this->info.y+4;
    this->screen->setTextColor(AMBER);
    this->screen->setTextSize(2);

    for (int i = 0; i < this->choices.size(); i++) {
        this->screen->setCursor(x, y);
        this->screen->setTextColor(AMBER);

        if (i == this->selection) {
            this->screen->fillRect(x-4, y-4, info.width, TEXT_SPACING, AMBER);
            this->screen->setTextColor(ILI9341_BLACK);
        }
        else {
            this->screen->fillRect(x-3, y-4, info.width-2, TEXT_SPACING, ILI9341_BLACK);
        }

        this->screen->println(this->choices[i]);
        y += TEXT_SPACING;
    }
    
}

void TaniMenu::cursorUp() {
    if (this->selection-1 < 0) {
        this->selection = this->choices.size()-1;
    } else {
        this->selection--;
    }
}

void TaniMenu::cursorDown() {
    if (this->selection+1 > this->choices.size()-1) {
        this->selection = 0;
    } else {
        this->selection++;
    }
}