#include <FastLED.h>

const int NUMLEDS = 8;
const int LEDPIN = 2;
const int LOWERBOUND = 0;
const int NUMPANELS = 6;
const int NUMCOLORS = 2;

CRGB leds[NUMLEDS];
const CRGB COLORS[NUMCOLORS] = {CRGB(1, 0, 0), CRGB(0, 1, 0)};

const int list[NUMPANELS] = {A0, A1, A2, A3, A4, A5};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUMPANELS; i++){
    pinMode(list[i], INPUT);
  }
  Serial.begin(9600);
  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMLEDS); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUMPANELS; i++){
    leds[NUMLEDS - 1 - i] = COLORS[i % NUMCOLORS] * map(analogRead(list[i]), LOWERBOUND, 1023, 0, 255);
  }
  FastLED.show();
}
