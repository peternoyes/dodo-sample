#include <stdio.h>
#include <stdlib.h>
#include "api.h"

int main() {
	unsigned int i = 0;
	unsigned char x = 0;
	
	api_init();

	CLEAR();


	for (;;) {
		SET_PIXEL(x, 10, 1);

		DISPLAY();

		SET_PIXEL(x, 10, 0);
		++x;
		
		LED_ON();
		WAIT();
		LED_OFF();
	}

	return 0;
}