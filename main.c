#include <stdio.h>
#include <stdlib.h>
#include "api.h"

#define VIDEO_MEM ((unsigned char *) 0x3c00)

int main() {
	unsigned int i = 0;
	
	api_init();

	
	for (i = 0; i < 1024; ++i) {
		VIDEO_MEM[i] = 0;
	}

	for (;;) {
		SET_PIXEL(10, 10, 1);

		DISPLAY();
		
		LED_ON();
		WAIT();
		LED_OFF();
	}

	return 0;
}