#include "raster.h"
#include <graphicsmath0/vec2.h>
#include "SDL/SDL.h"

SDL_Surface *screen;

void quit(int);

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) quit(1);
	screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
	//screen = SDL_CreateRGBSurface(0, 640, 480, 32, 0, 0, 0, 0);
	pr_setsurface(screen);
	pr_color(.5, .5, 1);
	pr_linecolor(.5, 1, .4);
	pr_line(vec2(.1, -.1), vec2(.5, .5));
	pr_pointsize(2);
	pr_point(vec2(0, 0));
	pr_point(vec2(.1, .1));
	pr_point(vec2(-.5, .1));
	SDL_Flip(screen);
	SDL_Delay(1000);
	quit(0);
}

void quit(int rc) {
	SDL_Quit();
	exit(rc);
}
