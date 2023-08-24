/*
1- Tools  -> Board -> "ATtiny85 (No Bootloader)"
2- Tools  -> Port
2- Tools  -> Programmer -> "Arduino as ISP"
3- Tools  -> Burn bootloader
4- Sketch -> Upload Using Programmer
*/

#define IR_SEND_PIN 0
#define RADAR_RECIVE_PIN 2
#define TV_ADDRESS 0x4

#include "TvControl.h"
#include <IRremote.hpp>

IRsend transmiter;

bool slepping = false;
unsigned long sleppingTime;
const unsigned long delays = 290000;  //Shutdown time when not in use (radar 10" + 4'50" = 5 min)

void setup() {
  pinMode(RADAR_RECIVE_PIN, INPUT);
  delay(20000);                       //Wait for the WebOS system to start (about 20" seconds)
}

void loop() {
  if (!digitalRead(RADAR_RECIVE_PIN) && !slepping) {
    transmiter.sendNEC(TV_ADDRESS, General::ENERGY_SAVER, 0);
    sleppingTime = millis();
    slepping = true;
  } else if (digitalRead(RADAR_RECIVE_PIN) && slepping) {
    transmiter.sendNEC(TV_ADDRESS, Media::PLAY, 0);
    slepping = false;
  } else if (slepping && (millis() > sleppingTime + delays)) {
    transmiter.sendNEC(TV_ADDRESS, General::POWER, 0);
    delay(10000);                     //Wait for the shutdown process to turn off USB power (10" at most)
  }

  delay(200);
}
