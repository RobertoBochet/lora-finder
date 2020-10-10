#ifndef MAIN_H
#define MAIN_H

//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

#include "config.h"
#include "packet.h"
#include "logo.h"


#include "global.h"


void display_data();

bool send_packet();

#endif
