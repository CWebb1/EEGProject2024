#include <avr/wdt.h>
#include <EEGLED.h>

const int EEG_PIN = A0;
int eegValue;    // EEG value within the range
const int LED_PIN_1 = 7;    // digital pin for LED 1
const int LED_PIN_2 = 6;    // digital pin for LED 2
const int LED_PIN_3 = 5;    // digital pin for LED 3

ledChange myLed(eegValue);  // Create an instance of ledChange with initial EEG value

void setup() {
  Serial.begin(9600);
  wdt_enable(WDTO_15MS);
  myLed.begin(LED_PIN_1, LED_PIN_2, LED_PIN_3);  // Initialize the library with LED pins
}

void loop() {
  eegRead();
  myLed.change();  // Call change() method to change LED state based on EEG value
  delay(10);     // Delay for readability in serial monitor
  wdt_reset(); // Watchdog timer reset
}

void eegRead(){
  eegValue = analogRead(EEG_PIN); //Reads EEG Value
  Serial.println(eegValue); // Prints EEG Value
}
