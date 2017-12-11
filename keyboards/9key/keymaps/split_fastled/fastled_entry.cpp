#include "fastled_entry.h"
#include "timer3.h"

#include "bootstrap/_Arduino.h"
#include <FastLED.h>

#include <common/print.h>

#define NUM_LEDS 6
#define DATA_PIN 1

void fastled_show(void);

CRGB leds[NUM_LEDS];
uint32_t refresh;

/**
 * void fastled_init(void)
 */
void fastled_init(void) {
  timer3_init();

  // Disable blocking - probably not needed as the loop takes longer
  CLEDController *pLed = &FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  refresh = pLed->getMaxRefreshRate();
  FastLED.setMaxRefreshRate(0,false);

  FastLED.setMaxPowerInVoltsAndMilliamps(5,400);
  FastLED.setBrightness(40);
}

/**
 * void fastled_update(void)
 */
void fastled_update(void) {

  // how often to update the pixel data
  EVERY_N_SECONDS(2) {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(random8(),255,255);
    }
  }
  
  fastled_show();

  // monitoing on hid listen
  EVERY_N_SECONDS(1) {
    xprintf("test\n");
  }
}

/**
 * void fastled_show(void)
 * A non-blocking show command.  Most likely not needed from my testing as the loop takes longer than 400 micros
 * which is the refresh rate of neopixels in the library.
 */
inline void fastled_show(void) {
  static uint32_t lastshow = 0;
  if((micros() - lastshow) > refresh) {
    FastLED.show();
    lastshow = micros();
  }

}
