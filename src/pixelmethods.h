#ifndef PIRASTER_PIXELMETHODS_INC
#define PIRASTER_PIXELMETHODS_INC

#include <SDL/SDL.h>
#include <graphicsmath0/vec3.h>

/// The surface that pixelmethods should draw to
extern SDL_Surface * piraster_screen;

/**
 * @brief Set the surface to draw to (pixelmethods_screen)
 * @param A pointer to the surface to use
 */
void setrastersurface(SDL_Surface *);

/**
 * @brief Set the color to use if the function doesn't specify one
 * @param The red component [0 - 1]
 * @param The green component [0 - 1]
 * @param The blue component [0 - 1]
 */
void setrastercolor(float, float, float);

/**
 * @overload
 * @param The color to use, already converted to a Uint32 (internal format)
 */
void setrastercolor(Uint32);

/**
 * @brief Convert a color from Uint32 format to a vec4
 * @param The color in Uint32 format (used by SDL)
 * @return The color as a vec4
 */
vec3 uinttocolor(Uint32);

/**
 * @brief Convert a color from a vec4 to Uint32 format
 * @param The red component [0 - 1]
 * @param The green component [0 - 1]
 * @param The blue component [0 - 1]
 * @return The color in Uint32 format (used by SDL)
 */
Uint32 colortouint(float, float, float);

/**
 * @brief Get the color of the pixel at (x, y)
 * @param The x component to check at
 * @param The y component to check at
 * @return The color of the pixel as a vec4
 */
vec3 getpixel(int, int);

/**
 * @brief Set the color of the pixel at (x, y)
 * @param The x component to check at
 * @param The y component to check at
 * @param The color to set formatted as a Uint32
 */
void setpixel(int, int, Uint32);

/**
 * @brief Set the color of the pixel at (x, y)
 * @param The x component to check at
 * @param The y component to check at
 * @param The color to set formatted as a vec4
 */
void setpixel(int, int, vec3);

/**
 * @brief Set the color of the pixel at (x, y) to the current rastercolor
 * @param The x component to check at
 * @param The y component to check at
 */
void setpixel(int, int);

#endif
