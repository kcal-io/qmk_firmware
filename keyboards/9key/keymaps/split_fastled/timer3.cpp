#include "timer3.h"

#include "bootstrap/_Arduino.h"

#include <common/print.h>

#include <avr/io.h>

#define MICROSECONDS_PER_TIMER0_OVERFLOW (clockCyclesToMicroseconds(65536 * 64))
#define MILLIS_INC (MICROSECONDS_PER_TIMER0_OVERFLOW / 1000)
#define FRACT_INC ((MICROSECONDS_PER_TIMER0_OVERFLOW % 1000) >> 3)
#define FRACT_MAX (1000 >> 3)

// backwards compatibility with FastLED expecting Timer0
volatile unsigned long timer0_millis = 0; 

#define timer3_millis timer0_millis
volatile unsigned long timer3_overflow_count = 0;
static unsigned char timer3_fract = 0;

void timer3_init(void) {
  TCCR3A = 0;
	TCCR3B = _BV(CS31) | _BV(CS30);
	TIMSK3 = _BV(TOIE3);

	sei();
}

unsigned long millis() {
	unsigned long m;
	uint8_t oldSREG = SREG;

	cli();
	m = timer3_millis;
	SREG = oldSREG;

	return m;
}

unsigned long micros() {
	unsigned long m;
	uint8_t oldSREG = SREG;
  uint16_t t;
	
	cli();
	m = timer3_overflow_count;
	t = TCNT3;

  if ((TIFR3 & _BV(TOV3)) && (t < 65535))
		m++;

	SREG = oldSREG;
	
	return ((m << 16) + t) * (64 / clockCyclesPerMicrosecond());
}

void delay(unsigned long ms) {
  uint32_t start = micros();

	while (ms > 0) {
		yield();
		while ( ms > 0 && (micros() - start) >= 1000) {
			ms--;
			start += 1000;
		}
	}
}

ISR(TIMER3_OVF_vect) {
	unsigned long m = timer3_millis;
	unsigned char f = timer3_fract;

	m += MILLIS_INC;
	f += FRACT_INC;
	if (f >= FRACT_MAX) {
		f -= FRACT_MAX;
		m += 1;
	}

	timer3_fract = f;
	timer3_millis = m;
	timer3_overflow_count++;
}
