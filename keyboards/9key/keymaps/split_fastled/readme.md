## Updating QMK Core and Submodules:
```
get pull https://github.com/qmk/qmk_firmware.git master
git submodule update --recursive --remote
git status
git add -A
git commit -m "Updating to latest version of QMK"
```

## Adding Libraries for the Keymap:
This is probably not the best method as it brings in a lot of unnecessary code.  I am not overly familiar with the intricacies of version control and the make system, but the design goal here was to be able to sync with the latest code in the core libraries rather than pulling in snippets and modifying, thus introducing fragmentation.  However, it is possible to get away with only a few dozen lines from the Arduino library to bootstrap FastLED.
```
git submodule add https://github.com/FastLED/FastLED lib/FastLED
git submodule add https://github.com/arduino/Arduino.git lib/Arduino
git submodule add https://github.com/sparkfun/Arduino_Boards.git lib/Sparkfun
```

## Required Patching
### Arduino_patched.h
The function definition needed to be changed for atexit in Arduino.h for wiring.h to compile.  TODO, script to do this automatically.

## Bulding
```
make 9key/split_fastled
```
