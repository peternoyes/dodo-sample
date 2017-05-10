#include <stdio.h>
#include <stdlib.h>
#include "api.h"

static unsigned char const _ball[8] = { 0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c }; 
static unsigned char const _ball_mask[8] = { 0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3 };
static unsigned char const _hatch[8] = { 0x55, 0x55, 0xaa, 0xaa, 0x55, 0x55, 0xaa, 0xaa };
static unsigned char const _cursor[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
static unsigned char const _cursor2[32] = { 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x1f, 0x1f, 0x3f, 0xff, 0xff, 0x77, 0x23, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

int main() {
	unsigned char* ball = (unsigned char*)_ball;
	unsigned char* ball_mask = (unsigned char*)_ball_mask;
	unsigned char* hatch = (unsigned char*)_hatch;
	unsigned char* cursor = (unsigned char*)_cursor;
	unsigned char* cursor2 = (unsigned char*)_cursor2;

	unsigned char p, x, y, xdir, ydir = 0;
	//unsigned char xdir = 0;				// For some reason this being declared on previous line causes bug on real hardware. Need to investigate.

	// Create a buffer to store the portion of the background behind the ball.
	// The buffer much be large enough to store the sprite and an additonal row of data
	// If the sprite were 24x16, the buffer would need to be an additional 24 bytes larger
	unsigned char* buffer = (unsigned char*)malloc(16);

	api_init();					// Initialize the API

	CLEAR();					// Clear the screen

	for (p = 0; p < 128; p += 8) {
		for (y = 0; y < 64; y += 8) {
			DRAW_SPRITE(hatch, p, y, 8, 8, 0, DRAW_NOP);
		}
	}

	SET_CURSOR(3, 3);				// Row, Col
	DRAW_STRING("Hello World!");

	//DRAW_SPRITE(cursor, 8, 8, 8, 8, 0, DRAW_XOR);

	x = 0;
	y = 20;

	for (;;) {
		COPY_BACKGROUND(buffer, x, y, 16, 16, 0);	// Copy background into buffer

		//DRAW_SPRITE(ball_mask, x, y, 8, 8, 1, DRAW_AND);
		//DRAW_SPRITE(ball, x, y, 8, 8, 1, DRAW_OR);

		DRAW_SPRITE(cursor2, x, y, 16, 16, 1, DRAW_XOR);
		

		DISPLAY();				// Push contents of video memory to screen (expensive call)

		COPY_BACKGROUND(buffer, x, y, 16, 16, 1);	// Copy buffer back into video memory, thus erasing the sprite

		
		if (xdir == 0) {
			++x;
			if (x > 112) {
				x = 112;
				xdir = 1;
			}
		} else if (xdir == 1) {
			--x;
			if (x > 127) {
				x = 0;
				xdir = 0;
			}
		}

		
		if (ydir == 0) {
			++y;
			if (y > 48) {
				y = 48;
				ydir = 1;
			}
		} else if (ydir == 1) {
			--y;
			if (y > 127) {
				y = 0;
				ydir = 0;
			}
		}
		
		WAIT();					// Wait for next interrupt, sync game loop
	}

	return 0;
}