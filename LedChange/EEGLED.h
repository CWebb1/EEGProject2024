#ifndef EEGLED_h
#define EEGLED_h

#include "Arduino.h"

class ledChange {
  public:
    ledChange(int eegValue);  // Constructor declaration with parameter

    void begin(int pin1, int pin2, int pin3);  // Method declaration to initialize LED pins

    void change(); // Method declaration for changing LED state based on EEG value

  private:
    int _eegValue;  // Private member variable to store EEG value
    int _ledPins[3];  // Array to store LED pin numbers

    // Private methods or additional private variables can be added here
};

#endif
