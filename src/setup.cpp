#include <esp_bt_main.h>
#include <esp_bt.h>
#include <esp_wifi.h>
#include <beacon.h>
#include "global.h"
#include "loop.h"

bool shutdown_useless_perifericals()
{
	//esp_bluedroid_disable();
	//esp_bt_controller_disable();
	//esp_wifi_stop();

	return true;
}

bool init_gpio()
{
	pinMode(DEVICE_MODE_PIN, INPUT_PULLUP);
	pinMode(GPS_PWR, OUTPUT);

	return true;
}

bool init_screen(bool with_splash = false)
{
	// initializes screen
	Wire.begin(SCREEN_SDA, SCREEN_SCL);

	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, true, false)) return false;

	// inits display
	display.setTextColor(WHITE);
	display.setTextSize(1);
	display.clearDisplay();
	display.setCursor(0, 0);
	display.display();

	if (with_splash)
	{
		// shows logo
		display.clearDisplay();
		display.drawBitmap(0, 0, logo, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
		display.display();

		delay(3000);

		// clears display
		display.clearDisplay();
		display.setCursor(0, 0);
		display.display();
	}

	return true;
}

bool init_lora()
{
	//SPI LoRa pins
	SPI.begin(LORA_SCK, LORA_MISO, LORA_MOSI, LORA_SS);
	//setup LoRa transceiver module
	LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);


	if (LoRa.begin(LORA_BAND))
	{
		LoRa.setSyncWord(LORA_SYNCWORD);
		LoRa.enableCrc();
		return true;
	}
	return false;
}

bool init_gps()
{
	// starts communication with GPS
	gps_serial.begin(GPS_BAUD);
	while (!gps_serial) delay(100);

	return true;
}

void debug_print()
{
	display.printf("%d:%d:%d\n", sizeof(uint16_t), sizeof(float), sizeof(double));
	display.printf("%d:%d\n", PACKET_T_SIZE, PACKET_SIZE);
	//display.printf("%x\n%x\n", packet_struct._protocol, packet_class._protocol);
	display.printf("%d\n", sizeof(logo));
	display.display();
	delay(2000);
}

void setup()
{
	// initializes serial for debug
	Serial.begin(SERIAL_BAUD);

	shutdown_useless_perifericals();

	init_gpio();

	// if mode button is pressed at the first boot then it starts the device in mapper mode
	if (digitalRead(DEVICE_MODE_PIN) == DEVICE_MODE_LEVEL && esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_UNDEFINED)
		current_mode = device_mode_t::DEVICE_MODE_MAPPER;

	// powers on the gps
	digitalWrite(GPS_PWR, HIGH);

	if (current_mode == device_mode_t::DEVICE_MODE_MAPPER)
	{
		if (!init_screen(true))
		{
			Serial.println(F("Screen initialization failed"));
			while (true);
		}
		Serial.println("Screen initialized");
	}

	// initializes LoRa module
	if (!init_lora())
	{
		Serial.println("LoRa initialization failed!");
		while (true);
	}

	Serial.println("LoRa initialized");

	init_gps();

	Serial.println("GPS initialized");

	if (current_mode == device_mode_t::DEVICE_MODE_BEACON) beacon_task();

	//debug_print();
}
