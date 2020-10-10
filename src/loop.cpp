#include <render.h>
#include "loop.h"

void loop()
{
	auto a = LoRa.parsePacket(sizeof(Packet::buffer));
	if (a == sizeof(Packet::buffer))
	{

		Serial.println(F("A packet was received"));
		Serial.println(a);
		Serial.println(LoRa.available());

		LoRa.readBytes((uint8_t *) &packet.buffer, sizeof(Packet::buffer));

		Serial.print(F("lat="));
		Serial.println(packet.get_latitude(), 6);
		Serial.print(F("lng="));
		Serial.println(packet.get_longitude(), 6);
	}
	else if(a > 0)
	{
		Serial.println(F("no received"));
		Serial.println(a);
	}


	while (gps_serial.available() > 0)
		gps.encode(gps_serial.read());


	render();
}

void display_data()
{
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(1);

	display.setCursor(0, 0);

	display.printf("%02d:%02d:%02d %02d/%02d/%d\n",
				   gps.time.hour(), gps.time.minute(), gps.time.second(),
				   gps.date.day(), gps.date.month(), gps.date.year());
	display.printf("lat=%.6f%c\n", abs(gps.location.lat()), gps.location.rawLat().negative ? 'S' : 'N');
	display.printf("lng=%.6f%c\n", abs(gps.location.lng()), gps.location.rawLng().negative ? 'W' : 'E');
	display.printf("alt=%.2fm\n", gps.altitude.meters());
	display.printf("spd=%.2fkm/h\n", gps.speed.kmph());
	display.printf("age=%dus\n", gps.date.age());
	display.printf("sat=%d\n", gps.satellites.value());

	display.display();
}