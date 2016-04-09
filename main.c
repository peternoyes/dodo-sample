#include <stdio.h>
#include <stdlib.h>
#include "api.h"

int main() {
	unsigned char x = 0;
	
	api_init();					// Initialize the API

	CLEAR();					// Clear the screen


	for (;;) {
		SET_PIXEL(x, 10, 1);	// Set pixel

		DISPLAY();				// Push contents of video memory to screen (expensive call)

		SET_PIXEL(x, 10, 0);	// Clear Pixel
		++x;
		
		WAIT();					// Wait for next interrupt, sync game loop
	}

	return 0;
}