#include "Display.h"

void Display::setup()
{
    #define AddLeds(x) FastLED.addLeds<NEOPIXEL, DataPin##x>(leds[x], NumLedsPerStrip)
    if (NumStrips > 0) AddLeds(0);
    if (NumStrips > 1) AddLeds(1);
    if (NumStrips > 2) AddLeds(2);
    #undef AddLeds

    clear();

    FastLED.setBrightness(Brightness);
}

void Display::loop()
{
    FastLED.show();
}

void Display::clear(bool refresh)
{
    memset(leds, 0, NumStrips * NumLedsPerStrip * 3);

    if (refresh)
        FastLED.show();
}

void Display::fadeToBlackBy(uint8_t amount)
{
    for (uint8_t strip = 0; strip < NumStrips; strip++)
    {
        ::fadeToBlackBy(leds[strip], NumLedsPerStrip, amount);
    }
}