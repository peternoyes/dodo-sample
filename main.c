#include <stdio.h>
#include <stdlib.h>
#include "api.h"

static unsigned char const _ball[8] = { 0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c }; 
static unsigned char const _ball_mask[8] = { 0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3 };
static unsigned char const _hatch[8] = { 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa };

int main() {
	unsigned char* ball = (unsigned char*)_ball;
	unsigned char* ball_mask = (unsigned char*)_ball_mask;
	unsigned char* hatch = (unsigned char*)_hatch;

	unsigned char p, x, y, dir = 0;
	
	x = 10;

	api_init();					// Initialize the API

	CLEAR();					// Clear the screen


	for (;;) {
		for (p = 0; p < 128; p += 8) {
			DRAW_SPRITE(hatch, p, 0, 8, 8, 0, DRAW_NOP);
			DRAW_SPRITE(hatch, p, 8, 8, 8, 0, DRAW_NOP);
		}

		DRAW_SPRITE(ball_mask, x, y, 8, 8, 0, DRAW_AND);
		DRAW_SPRITE(ball, x, y, 8, 8, 0, DRAW_OR);

		DISPLAY();				// Push contents of video memory to screen (expensive call)

		++x;
		if (x > 120) {
			x = 0;
		}

		if (dir == 0) {
			++y;
			if (y > 8) {
				y = 8;
				dir = 1;
			}
		} else if (dir == 1) {
			--y;
			if (y > 127) {
				y = 0;
				dir = 0;
			}
		}
		
		WAIT();					// Wait for next interrupt, sync game loop
	}

	return 0;
}