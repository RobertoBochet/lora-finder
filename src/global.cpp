#include "global.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, SCREEN_RST);

SoftwareSerial gps_serial(GPS_RX, GPS_TX); // serial connection to the GPS device
TinyGPSPlus gps; // gps parser

Packet packet(DEVICE_ID);

device_mode_t current_mode = device_mode_t::DEVICE_MODE_BEACON;