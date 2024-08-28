#ifndef AXIS_H
#define AXIS_H

#include <stddef.h>
#include <stdlib.h>

// Define the Axis struct
typedef struct{
    double center_x; 
    double center_y; 
    double width_x;
    double width_y;
    int dense;
} Axis;

// Function declarations
Axis* create_axis(double center_x, double center_y, double width_x, double width_y, int dense);
void update_axis(Axis* axis, double zoom_x, double zoom_y);

#endif // AXIS_H
