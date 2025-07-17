#include "EEGLED.h"

// Constructor definition
ledChange::ledChange(int eegValue) {
  _eegValue = eegValue;  // Initialize private member variable
  // Additional initialization if needed
}

void ledChange::begin(int pin1, int pin2, int pin3) {
  _ledPins[0] = pin1;  // Store pin1 in array
  _ledPins[1] = pin2;  // Store pin2 in array
  _ledPins[2] = pin3;  // Store pin3 in array

  // Initialize LED pins as outputs
  pinMode(_ledPins[0], OUTPUT);
  pinMode(_ledPins[1], OUTPUT);
  pinMode(_ledPins[2], OUTPUT);
}

void ledChange::change() {
  // Check if _eegValue is within the range of 0 to 10
  if (_eegValue >= 0 && _eegValue <= 10) {
    // Turn on Red LEDs
    digitalWrite(_ledPins[0], HIGH);
    digitalWrite(_ledPins[1], LOW);
    digitalWrite(_ledPins[2], LOW);
  }else if(_eegValue >= 11 && _eegValue <= 20){
    // Turn on Yellow LEDs
    digitalWrite(_ledPins[0], LOW);
    digitalWrite(_ledPins[1], HIGH);
    digitalWrite(_ledPins[2], LOW);
  }else if(_eegValue >= 21 && _eegValue <= 30){
    // Turn on Blue LEDs
    digitalWrite(_ledPins[0], LOW);
    digitalWrite(_ledPins[1], LOW);
    digitalWrite(_ledPins[2], HIGH);
  } 
  else {
    // Turn on all LEDs
    digitalWrite(_ledPins[0], HIGH);
    digitalWrite(_ledPins[1], HIGH);
    digitalWrite(_ledPins[2], HIGH);
  }
}
