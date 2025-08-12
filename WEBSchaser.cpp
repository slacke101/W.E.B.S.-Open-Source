// rafael castro //
//    8/11/25    //
// ** ATTENTOIN ** //
// snippet is for WEBS' 6 installed LEDs, chaser effect going forward and backwards //

class leds {
  public:
    int ledPins[6] = {8, 9, 10, 11, 12, 13};  // pins where the leds are connected
    int totLEDs = 6;                          // total number of leds

    void initPins() {
      for (int i = 0; i < totLEDs; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
      }
    }

    void turnOn(int index) {
      if (index >= 0 && index < totLEDs) {
        digitalWrite(ledPins[index], HIGH);
      }
    }

    void turnOff(int index) {
      if (index >= 0 && index < totLEDs) {
        digitalWrite(ledPins[index], LOW);
      }
    }
};

leds leds;

void setup() {
  leds.initPins();  // initialize pins once at the start
}

void loop() {
  // chaser going forward
  for (int i = 0; i < leds.totLEDs; i++) {
    leds.turnOn(i);
    delay(150);
    leds.turnOff(i);
  }

  // chaser going backward
  for (int i = leds.totLEDs - 2; i > 0; i--) {  // skip first and last so no double blink
    leds.turnOn(i);
    delay(150);
    leds.turnOff(i);
  }
}
