#include <global.h>
#include <LoRa.h>
#include "beacon.h"

void handle_gps_timeout()
{
	Serial.println(F("GPS timeout"));

	// TODO: implement a handler for gps timeout
	packet.set_latitude(10.0);
	packet.set_latitude(-15.0);

	LoRa.idle();
	LoRa.beginPacket();
	LoRa.write((uint8_t *) &packet.buffer, sizeof(Packet::buffer));
	LoRa.endPacket();
	LoRa.sleep();

	Serial.println(F("Packet was sent"));

	esp_sleep_enable_timer_wakeup((BEACON_PERIOD - millis()) * (int) 1e3);
	esp_deep_sleep_start();
}

void send_data()
{
	packet.set_latitude(gps.location.lat());
	packet.set_latitude(gps.location.lng());

	LoRa.idle();
	LoRa.beginPacket();
	LoRa.write((uint8_t *) &packet.buffer, sizeof(Packet::buffer));
	LoRa.endPacket();
	LoRa.sleep();

	Serial.println(F("Packet was sent"));
}

void beacon_task()
{
	do
	{
		while (gps_serial.available() > 0) gps.encode(gps_serial.read());
	} while (!gps.location.isValid() && millis() < BEACON_GPS_TIMEOUT);

	if (!gps.location.isValid()) handle_gps_timeout();

	send_data();

	esp_sleep_enable_timer_wakeup((BEACON_PERIOD - millis()) * (int) 1e3);
	esp_deep_sleep_start();
}


