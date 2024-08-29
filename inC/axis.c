#include <stddef.h>
#include "axis.h"
#include <stdio.h>

Axis* create_axis(double center_x, double center_y, double width_x, double width_y, int dense) {
    // Dynamically allocate memory for an Axis struct
    Axis* axis = (Axis*)malloc(sizeof(Axis));
    
    // Check if the memory allocation was successful
    if (axis == NULL) {
        // Handle the error if memory allocation failed (optional)
        return NULL;
    }

    // Initialize the struct members
    axis->center_x = center_x;
    axis->center_y = center_y;
    axis->width_x = width_x;
    axis->width_y = width_y;
    axis->dense = dense;

    // Return the pointer to the allocated and initialized struct
    return axis;
}


void update_axis(Axis* axis, double zoom_x, double zoom_y) {
    if (axis == NULL) {
        return;
    }
    
    axis->width_x *= zoom_x;
    axis->width_y *= zoom_y;
}



void constructer_axis(double* array, double start, double end, int num_points) {
    if (num_points <= 0) {
        printf("Number of points must be positive.\n");
        return;
    }
    double step = (end - start) / (num_points - 1);

    for (int i = 0; i < num_points; i++) {
        array[i] = start + i * step;
    }
}
