#include "render.h"

void render()
{
	display.clearDisplay();

	display.setCursor(0, 0);
	display.print(F("Beacon in range: "));
	display.print(45);

	display.setCursor(0, 50);
	if (gps.location.isValid())
	{
		display.print(F("lat="));
		display.print(gps.location.lat(), 6);
		display.print(F(" lng="));
		display.print(gps.location.lng(), 6);
	} else
	{
		display.print("Waiting GPS signal");
	}

	display.display();
}
