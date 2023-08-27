/*
1- Tools  -> Board -> "ATtiny85 (No Bootloader)"
2- Tools  -> Port
2- Tools  -> Programmer -> "Arduino as ISP"
3- Tools  -> Burn bootloader
4- Sketch -> Upload Using Programmer
*/

#define IR_SEND_PIN 0
#define RADAR_RECIVE_PIN 2
#define BT_ENABLE_PIN 1
#define TV_ADDRESS 0x4
#define SERIAL_RX_PIN 3
#define SERIAL_TX_PIN 4

#include "TvControl.h"
#include "RadarControl.h"
#include <IRremote.hpp>
#include <SoftwareSerial.h>

SoftwareSerial tinnySerial(SERIAL_RX_PIN, SERIAL_TX_PIN);
IRsend transmiter;

bool slepping = false;
unsigned long sleppingTime;
const unsigned long delays = 290000;  //Shutdown time when not in use (radar 10" + 4'50" = 5 min)

void setup() {
  pinMode(RADAR_RECIVE_PIN, INPUT);
  pinMode(BT_ENABLE_PIN, INPUT);
  
  tinnySerial.begin(9600);
  radarSetup(BT_ENABLE_PIN);
  tinnySerial.end();

  delay(18700);                       //Wait for the WebOS system to start (about 20")
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

void radarSetup(int pin) {
  delay(1000);
  //Enable config mode
  sendCommand(Mode::SETUP, 14);
  //Setup bluetooth
  sendCommand(digitalRead(pin) ? Bluetooth::ENABLE : Bluetooth::DISABLE, 14);
  //Restart radar to take effect
  sendCommand(Mode::RESTART, 12);
}

void sendCommand(int config, const int len) {
  byte buffer[len];
  memcpy_P(buffer, command[config], sizeof(buffer));

  for (int i = 0; i < sizeof(buffer); i++) {
    tinnySerial.write(buffer[i]);
  }

  delay(100);
}
