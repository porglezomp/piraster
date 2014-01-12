#include "raster.h"
#include <graphicsmath0/vec2.h>
#include <graphicsmath0/mat3.h>

mat3 pr_viewmatrix;

// Set the SDL_Surface for functions to use
void pr_setsurface(SDL_Surface *s) {
	setrastersurface(s);
	// Also create the matrix to apply to input vertices
	pr_viewmatrix = mat3::identity();
	pr_viewmatrix.translate(s->w/2, s->h/2);
	pr_viewmatrix.scale(1.0/s->w*2, -1.0/s->h*2, 1);
}

inline vec2 transformvec(const vec2 &point) {
	vec2 p = vec2(point.x+1, 1-point.y)*vec2(piraster_screen->w, piraster_screen->h)/2;
	p.y = piraster_screen->h - p.y;
	return p;
}

int width = 640, height = 480;
void pr_point(const vec2 &point) {
	vec2 p = transformvec(point);
	drawpoint(p.x, p.y);
}

void pr_line(const vec2 &start, const vec2 &end) {
	vec2 s = transformvec(start);
 	vec2 e = transformvec(end);
	drawline(s.x, s.y, e.x, e.y);
}

void pr_tri(const vec2 &a, const vec2 &b, const vec2 &c) { } /// TODO: Implement

// Set colors
void pr_pointcolor(float r, float g, float b) {
	setpointcolor(r, g, b);
}

void pr_linecolor(float r, float g, float b) {
	setlinecolor(r, g, b);
}

void pr_tricolor(float r, float g, float b) { } /// TODO: Implement

void pr_color(float r, float g, float b) {
	pr_pointcolor(r, g, b);
	pr_linecolor(r, g, b);
	pr_tricolor(r, g, b);
}

// Set point size
void pr_pointsize(int i) {
	pointsize(i);
}
