#include "SDL/SDL.h"
#include "pixelmethods.h"
#include "graphicsmath0/vec3.h"

#define SATURATE(A)	if (A < 0) A = 0; else if (A > 1) A = 1;

SDL_Surface *piraster_screen;
Uint32 pixelmethods_currentcolor = 0xffffffff;

vec3 uinttocolor(Uint32 color) {
	Uint8 r, g, b;
	SDL_GetRGB(color, piraster_screen->format, &r, &g, &b);
	return vec3(r, g, b);
}

Uint32 colortouint(float r, float g, float b) {
	SATURATE(r); SATURATE(g); SATURATE(b);
	return SDL_MapRGB(piraster_screen->format, r*255, g*255, b*255);
}

void setrastersurface(SDL_Surface *s) {
	piraster_screen = s;
}

void setrastercolor(float r, float g, float b) {
	pixelmethods_currentcolor = colortouint(r, g, b);
}
void setrastercolor(Uint32 color) {
	pixelmethods_currentcolor = color;
}

/*
 * Return the pixel value at (x, y)
 * NOTE: The surface must be locked before calling this!
 */
Uint32 getpixeluint(int x, int y) {
    int bpp = piraster_screen->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)piraster_screen->pixels + y * piraster_screen->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;

    case 2:
        return *(Uint16 *)p;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;

    case 4:
        return *(Uint32 *)p;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

vec3 getpixel(int x, int y) {
	Uint8 r, g, b;
	SDL_GetRGB(getpixeluint(x, y), piraster_screen->format, &r, &g, &b);
	return vec3(r/255.0, g/255.0, b/255.0);
}

/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
void setpixel(int x, int y, vec3 color) {
	setpixel(x, y, colortouint(color.x, color.y, color.z));
}
void setpixel(int x, int y) {
	setpixel(x, y, pixelmethods_currentcolor);
}
void setpixel(int x, int y, Uint32 pixel) {
    if (x >= piraster_screen->w || x < 0 || y >= piraster_screen->h || y < 0) {
         return;
    }

    int bpp = piraster_screen->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)piraster_screen->pixels + y * piraster_screen->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(Uint16 *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}
