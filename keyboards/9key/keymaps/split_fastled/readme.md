## Updating QMK Core and Submodules:
```
git pull https://github.com/qmk/qmk_firmware.git master
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

## Timer
Timer3 is used to implement micros, millis, and delay functions expected by the Arduino/FastLED environment so it does not conflict with Timer0 used by QMK.

## Bulding
```
make 9key/split_fastled
```

## Gallery
https://i.imgur.com/Xw7YlS9.jpg

