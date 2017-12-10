#define FASTLED_HAS_MILLIS

// Undef conflicting definitions from config_common.h that is globally included
#ifdef F0
    #undef B0 
    #undef B1 
    #undef B2 
    #undef B3 
    #undef B4 
    #undef B5 
    #undef B6 
    #undef B7 
    #undef C0 
    #undef C1 
    #undef C2 
    #undef C3 
    #undef C4 
    #undef C5 
    #undef C6 
    #undef C7 
    #undef D0 
    #undef D1 
    #undef D2 
    #undef D3 
    #undef D4 
    #undef D5 
    #undef D6 
    #undef D7 
    #undef E0 
    #undef E1 
    #undef E2 
    #undef E3 
    #undef E4 
    #undef E5 
    #undef E6 
    #undef E7 
    #undef F0 
    #undef F1 
    #undef F2 
    #undef F3 
    #undef F4 
    #undef F5 
    #undef F6 
    #undef F7 
    #undef A0 
    #undef A1 
    #undef A2 
    #undef A3 
    #undef A4 
    #undef A5 
    #undef A6 
    #undef A7 
#endif

#ifndef __AVR_ATmega32U4__
#define __AVR_ATmega32U4__
#endif

#include <Arduino.h>
