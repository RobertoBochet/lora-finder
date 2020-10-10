#include "packet.h"


Packet::Packet(const uint16_t &device_id, const device_mode_t &device_mode)
{
	this->buffer._protocol_id = PROTOCOL_ID;
	this->buffer._device_id = device_id;
	this->buffer._device_mode = device_mode;
	this->buffer._latitude_raw = 0;
	this->buffer._longitude_raw = 0;
}


double Packet::get_latitude() const
{
	return this->buffer._latitude_raw / (double) (1e6);
}

double Packet::set_latitude(const double &value)
{
	return this->buffer._latitude_raw = (int) (value * 1e6);
}

double Packet::get_longitude() const
{
	return this->buffer._longitude_raw / (double) (1e6);
}

double Packet::set_longitude(const double &value)
{
	return this->buffer._longitude_raw = (int) (value * 1e6);
}


