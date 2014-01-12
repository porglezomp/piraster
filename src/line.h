#ifndef PIRASTER_LINE_H
#define PIRASTER_LINE_H

/**
 * @brief Draw a line using pixel coordinates
 * @param The x coordinate of the first point
 * @param The y coordinate of the first point
 * @param The x coordinate of the second point
 * @param The y coordinate of the second point
 */
void drawline(int, int, int, int);

/**
 * @brief Set the color to use when drawing lines
 * @param The red component [0 - 1]
 * @param The green component [0 - 1]
 * @param The blue component [0 - 1]
 */
void setlinecolor(float, float, float);

#endif
