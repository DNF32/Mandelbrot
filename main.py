import numpy as np
from fun import *

axis = Axis()


X, Y = build_grid(axis.center_x, axis.center_y, axis.width_x, axis.width_y, axis.dense)

max_iter = 300
height = X.shape[0]
width = X.shape[1]

display = np.empty((height, width), dtype='str')

for i in range(height):
    for j in range(width):
        counter = iter(X[i,j], Y[i,j], max_iter)
        display[i, j] = '@' if counter == max_iter else ' '

for row in display:
    print(''.join(row))

