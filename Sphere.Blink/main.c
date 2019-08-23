#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include <applibs/log.h>
#include <applibs/gpio.h>

// This method is based on the offical Visual Studio "Azure Sphere Blink Sample".
// In additon to the origin, this sample will iterate through all three LEDs of the
// MT3620 Azure Sphere Dev Kit.
//
//	Links:
//		GPIO mapping:
//		https://www.avnet.com/opasdata/d120001/medias/images/194/Block%20Diagram%20-%20Azure%20Sphere%20MT3620%20Starter%20Kit%20(v2).jpg
//
//		Other samples:
//		https://github.com/Azure/azure-sphere-samples
int main(void)
{
	// Timespec var.
	const struct timespec sleepTime = { 1, 0 };

	// Get LEDs via GPIO mapping.
	// 8 =	red
	// 9 =	green
	// 10 =	blue
	int leds[3] = {
		GPIO_OpenAsOutput(8, GPIO_OutputMode_PushPull, GPIO_Value_High),
		GPIO_OpenAsOutput(9, GPIO_OutputMode_PushPull, GPIO_Value_High),
		GPIO_OpenAsOutput(10, GPIO_OutputMode_PushPull, GPIO_Value_High)
	};

	// Send greeting to user.
	Log_Debug("\n'Sphere.Blink' started\n");

	// Ensure all gpio connects are open.
	// Check for error code for failure (below 0).
	if (leds[0] < 0 || leds[1] < 0 || leds[2] < 0)
	{
		// Log error.
		Log_Debug("Error opening GPIO: %s (%d).\n", strerror(errno), errno);

		// Exit with error code.
		return -1;
	}

	// Cycle (maybe) for ever.
	while (true)
	{
		// Iterate through all leds and let
		// them blink.
		for (int i = 0; i < 3; i++)
		{
			GPIO_SetValue(leds[i], GPIO_Value_Low);
			nanosleep(&sleepTime, NULL);
			GPIO_SetValue(leds[i], GPIO_Value_High);
			nanosleep(&sleepTime, NULL);
		}
	}

	// Exit with success.
	return 0;
}