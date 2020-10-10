#ifndef PACKET_H
#define PACKET_H

#include <cstdint>

#include "config.h"


typedef struct packet_t
{
	uint16_t _protocol = PROTOCOL_ID;
	uint16_t identifier = 0;
	double latitude = 0;
	double longitude = 0;
} packet_t;

typedef enum {
	DEVICE_MODE_BEACON,
	DEVICE_MODE_MAPPER
} device_mode_t;

class Packet
{
public:
	struct
	{
		uint16_t _protocol_id: 13;
		device_mode_t _device_mode: 1;
		uint16_t _device_id: 16;
		int32_t _latitude_raw: 29;
		int32_t _longitude_raw: 29;
	} buffer;

	explicit Packet(const uint16_t &protocol_id = 0x00, const device_mode_t &device_mode = device_mode_t::DEVICE_MODE_BEACON);

	double get_latitude() const;

	double set_latitude(const double &value);

	double get_longitude() const;

	double set_longitude(const double &value);

};

#define PACKET_T_SIZE sizeof(packet_t)
#define PACKET_SIZE sizeof(Packet)

#endif
