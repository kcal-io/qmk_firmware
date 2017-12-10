#include "fastled_entry.h"

#include "bootstrap/_Arduino.h"
#include <FastLED.h>

#include <common/print.h>
#include <timer.h>

#define NUM_LEDS 144
#define DATA_PIN 1

CRGB leds[NUM_LEDS];

void fastled_init(void) {
  init();
  //FastLED.setMaxPowerInVoltsAndMilliamps(5,400);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(40);
}

void fastled_update(void) {
  EVERY_N_SECONDS(2) {
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(random8(),255,255);
    }
  }
  FastLED.show();
  //FastLED.delay(1000);
  static uint32_t mil,mic,tr;
  mic = micros();
  mil = millis();
  tr = timer_read32();
  xprintf("test: %lu, %lu, %lu\n", mic, mil, tr);
}

