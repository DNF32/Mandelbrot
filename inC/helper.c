#include <stdlib.h>
#include "helper.h"
int iter(double c_real, double c_imag, int max_iter){
    double z_real = 0;
    double z_imag = 0;

    double temp_x = 0;
    double temp_y = 0;
    for(int i = 0; i < max_iter; i++){
        temp_x =z_real*z_real -   z_imag*z_imag + c_real;
        temp_y = 2 *z_real* z_imag + c_imag; 

        if(temp_x *temp_x + temp_y * temp_y > 4){
            return i; 
        }
        z_real = temp_x;
        z_imag = temp_y;
    }
    return max_iter; 
}


