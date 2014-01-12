#ifndef PIRASTER_POINT_H
#define PIRASTER_POINT_H

/**
 * @brief Draw a point onscreen
 * @param The x coordinate of the point to draw
 * @param The y coordiante of the point to draw
 */
void drawpoint(float, float);
/**
 * @brief Set the point size to use when drawing
 * @param The radius (in pixels) to use
 */
void pointsize(int);
/**
 * @brief Set the color to draw points with
 * @param The red component of the color [0 - 1]
 * @param The green component of the color [0 - 1]
 * @param The blue component of the color [0 - 1]
 */
void setpointcolor(float, float, float);

#endif
