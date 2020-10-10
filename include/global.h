#ifndef LORA_FINDER_GLOBAL_H
#define LORA_FINDER_GLOBAL_H

#include <Adafruit_SSD1306.h>

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#include "packet.h"

extern Adafruit_SSD1306 display;

extern SoftwareSerial gps_serial; // serial connection to the GPS device
extern TinyGPSPlus gps; // gps parser

extern Packet packet;

extern device_mode_t current_mode;

#endif
