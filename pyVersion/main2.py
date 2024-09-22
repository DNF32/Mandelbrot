import numpy as np
from fun import *
import time

axis = Axis()

print("\033[2J", end='')  # Clear the screen
print("\033[?25l", end='')  # Hide the cursor

try:
    for zoom_iteration in range(10):
        X, Y = build_grid(axis.center_x, axis.center_y, axis.width_x, axis.width_y, axis.dense)
        max_iter = 650
        height = X.shape[0]
        width = X.shape[1]
        display = np.empty((height, width), dtype='str')
        
        for i in range(height):
            for j in range(width):
                counter = iter(X[i,j], Y[i,j], max_iter)
                display[i, j] = '@' if counter == max_iter else ' '
        
        print("\033[H", end='')  # Move cursor to home position
        for row in display:
            print(''.join(row))
        
        axis.update(0.75, 0.75)
        time.sleep(0.5)  # Add a small delay to make the animation visible

finally:
    print("\033[?25h", end='')  # Show the cursor again