#ifndef	PIRASTER_RASTER_H
#define PIRASTER_RASTER_H

#include "pixelmethods.h"
#include "triangle.h"
#include "line.h"
#include "point.h"
struct SDL_Surface;
struct vec2;

void pr_setsurface(SDL_Surface *);

void pr_point(const vec2&);
void pr_line(const vec2&, const vec2&);
void pr_tri(const vec2&, const vec2&, const vec2&);

void pr_pointcolor(float, float, float);
void pr_linecolor(float, float, float);
void pr_tricolor(float, float, float);
void pr_color(float, float, float);

void pr_pointsize(int);

#endif
