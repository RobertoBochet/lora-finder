#ifndef LORA_FINDER_CONFIG_H
#define LORA_FINDER_CONFIG_H

#include <Arduino.h>

#define PROTOCOL_ID 0b1011011101111
#define DEVICE_ID 0xFFFF



// beacon mode
#define BEACON_GPS_TIMEOUT 100
#define BEACON_PERIOD 5000


// device
#define DEVICE_MODE_PIN 0
#define DEVICE_MODE_LEVEL LOW

// serial
#define SERIAL_BAUD 115200


// LoRa transceiver module
#define LORA_SCK 5
#define LORA_MISO 19
#define LORA_MOSI 27
#define LORA_SS 18
#define LORA_RST 14
#define LORA_DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define LORA_BAND 866E6

#define LORA_SYNCWORD 0x16


// screen
#define SCREEN_SDA 4
#define SCREEN_SCL 15
#define SCREEN_RST 16

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


// GPS
#define GPS_PWR 24
#define GPS_RX 34
#define GPS_TX 35

#define GPS_BAUD 9600

#endif
