#include "SDL/SDL.h"
#include "point.h"
#include "pixelmethods.h"

#define SATURATE(A)	if (A < 0) A = 0; else if (A > 1) A = 1

int psize = 1;
Uint32 piraster_pointcolor = 0xffffffff;

void drawpoint(float x, float y) {
	SDL_Rect r = {x - psize, y + psize, psize*2, psize*2};
	SDL_FillRect(piraster_screen, &r, piraster_pointcolor);
}

void pointsize(int s) {
	psize = s/2;
}

void setpointcolor(float r, float g, float b) {
	SATURATE(r); SATURATE(g); SATURATE(b);
	piraster_pointcolor = SDL_MapRGB(piraster_screen->format, r*255, g*255, b*255);
}
