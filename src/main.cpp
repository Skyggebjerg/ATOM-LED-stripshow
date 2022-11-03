//https://github.com/bertmelis/esp32WS2811

#include <Arduino.h>
#include <M5Stack.h>
#include <vector>
#include <Ticker.h>
#include <esp32WS2811.h>

//WS2811 AtomLED(27,1); //Atom egen LED
WS2811 ws2811(26, 300);
std::vector<WS2811Effect*> effects;
Ticker timer;

void nextEffect() {
  //Serial.print("starting next effect\n");
  ws2811.startEffect(effects[random(0, effects.size())]);
}

void setup() {
  //AtomLED.clearAll();  // turns off ATOM LED
  delay(2000);
  //Serial.begin(115200);
  //Serial.println("Booting");

  // add effects
  effects.push_back(new Circus(1000));
  effects.push_back(new SnowSparkle({82, 56, 13}, 3, 100, 500));
  effects.push_back(new Aurora);

  // output enable level shifter
  //pinMode(23, OUTPUT);
  //digitalWrite(23, HIGH);

  // start led strip
  ws2811.begin();

  // effect starts in 15 seconds...
  timer.attach(15, nextEffect);
}

void loop() {
  // nothing to do here
  delay(1);
}