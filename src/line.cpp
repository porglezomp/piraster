#include <SDL/SDL.h>
#include "pixelmethods.h"
#include "line.h"
#include <math.h>

#define SATURATE(A)	if (A < 0) A = 0; else if (A > 1) A = 1

Uint32 piraster_linecolor = 0xffffffff;

void setlinecolor(float r, float g, float b) {
	SATURATE(r); SATURATE(g); SATURATE(b);
	piraster_linecolor = SDL_MapRGB(piraster_screen->format, r*255, g*255, b*255);
}

// Internal function
void drawlinex(int x1, int y1, int x2, int y2) {
	int y = y1;
	int err = 0;
	int dx = x2 - x1, dy = y2 - y1;
	for (int x = x1; x < x2; x++) {
		err += dy;
		if (err > dx/2) {
			err -= dx;
			y++;
		} else if (err < -dx/2) {
			err += dx;
			y--;
		}
		setpixel(x, y);
	}
}
// Internal function
void drawliney(int x1, int y1, int x2, int y2) {
	int x = x1;
	int err = 0;
	int dx = x2 - x1, dy = y2 - y1;
	for (int y = y1; y < y2; y++) {
		err += dx;
		if (err > dy/2) {
			err -= dy;
			x++;
		} else if (err < -dy/2) {
			err += dy;
			x--;
		}
		setpixel(x, y);
	}
}

void drawline(int x1, int y1, int x2, int y2) {
	setrastercolor(piraster_linecolor);
	if (abs(x2 - x1) > abs(y2 - y1)) {
		if (x1 < x2) {
			drawlinex(x1, y1, x2, y2);
		} else {
			drawlinex(x2, y2, x1, y1);
		}
	} else {
		if (y1 < y2) {
			drawliney(x1, y1, x2, y2);
		} else {
			drawliney(x2, y2, x1, y1);
		}
	}
}
