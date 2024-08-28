#include "axis.h"
#include "helper.h"
#include <stdlib.h>
#include <stdio.h>


#define MAX_ITER 650
#define DENSE 200 

int main(){ 
    Axis* my_axis = create_axis(0.0, 0.0, 1.0, 1.0, DENSE);    if (my_axis == NULL) {
        printf("Failed to create Axis object.\n");
        return 1;
    }

   double* X = linspace(my_axis->center_x - my_axis->width_x/2, my_axis->center_x + my_axis->width_x/2, DENSE); 
   double* Y = linspace(my_axis->center_y - my_axis->width_y/2, my_axis->center_y + my_axis->width_y/2, DENSE);

   char display[DENSE][DENSE]; 
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
   

   // Print the display array to the console
    for (int i = 0; i < DENSE; i++) {
        for (int j = 0; j < DENSE; j++) {
            printf("%c", display[j][DENSE-1 - i]);  // Print each character
        }
        printf("\n");  // Print a newline after each row
    }

    // Free the allocated memory for the Axis object
    free(my_axis);
    free(X);
    free(Y);

    return 0;
}
 