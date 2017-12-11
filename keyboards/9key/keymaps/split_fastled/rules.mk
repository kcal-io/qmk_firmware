RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
CONSOLE_ENABLE = yes
UNICODE_ENABLE = no
API_SYSEX_ENABLE = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

FASTLED_PATH = $(LIB_PATH)/FastLED
ARDUINO_PATH = $(LIB_PATH)/Arduino/hardware/arduino/avr/cores/arduino
SPARKFUN_PATH = $(LIB_PATH)/Sparkfun/sparkfun/avr/variants/promicro

VPATH += $(FASTLED_PATH) \
				 $(ARDUINO_PATH) \
				 $(SPARKFUN_PATH)

SRC += fastled_entry.cpp \
			 timer3.cpp \
			 bootstrap/_FastLED.cpp \
			 bootstrap/_bitswap.cpp \
			 bootstrap/_colorpalettes.cpp \
			 bootstrap/_colorutils.cpp \
			 bootstrap/_hsv2rgb.cpp \
			 bootstrap/_lib8tion.cpp \
			 bootstrap/_noise.cpp \
			 bootstrap/_power_mgt.cpp
