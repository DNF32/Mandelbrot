#include "axis.h"
#include "helper.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // Include this for sleep function

#define MAX_ITER 650
#define DENSE 200 

int main(){ 
    Axis* my_axis = create_axis(0.15, 0.0, 5.0, 2.0, DENSE);   
     if (my_axis == NULL) {
        printf("Failed to create Axis object.\n");
        return 1;
    }
    char display[DENSE][DENSE]; 
    double X[DENSE];
    double Y[DENSE];
    for(int i = 0; i < 100; i++){

        constructer_axis(X, my_axis->center_x - my_axis->width_x/2, my_axis->center_x + my_axis->width_x/2, DENSE); 
        constructer_axis(Y, my_axis->center_y - my_axis->width_y/2, my_axis->center_y + my_axis->width_y/2, DENSE);

        for (int i = 0; i < DENSE; i++) {
            for (int j = 0; j < DENSE; j++) {
                int counter = iter(X[i], Y[j], MAX_ITER);
                if (counter < MAX_ITER) {
                    display[i][j] = ' ';  // Use single quotes for characters
                } else {
                    display[i][j]= '#';  // Use single quotes for characters
                }
            }
        }

        // ANSI escape code to clear the screen and move the cursor to the top left corner
        printf("\033[2J\033[H");

        // Print the display array to the console
        for (int i = 0; i < DENSE; i++) {
            for (int j = 0; j < DENSE; j++) {
                printf("%c", display[j][DENSE-1 - i]);  // Print each character
            }
            printf("\n");  // Print a newline after each row
        }
        fflush(stdout);

        update_axis(my_axis, 0.75, 0.75);
        usleep(10000);
    }
    // Free the allocated memory for the Axis object
    free(my_axis);

    return 0;
}
 