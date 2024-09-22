import numpy as np

def iter(c_real, c_imag, max_iter):
    z_real, z_imag = 0, 0
    for i in range(max_iter):
        z_real, z_imag = (z_real*z_real - z_imag*z_imag + c_real,
                          2*z_real*z_imag + c_imag)
        if z_real*z_real + z_imag*z_imag > 4:
            return i
    return max_iter 

def build_grid(center_x=0.15, center_y=0.15, width_x=1, width_y=1, dense = 200):
    x_min, x_max = center_x - width_x/2,  center_x + width_x/2
    y_min, y_max = center_y - width_y/2,  center_y + width_y/2

    width, height = dense, dense  

    x = np.linspace(x_min, x_max, width)
    y = np.linspace(y_min, y_max, height)
    X, Y = np.meshgrid(x, y)
    return X, Y 

class Axis:
    def __init__(self, center_x=0.35, center_y=0.25, width_x=2, width_y=2, dense = 100):
        self.center_x = center_x
        self.center_y = center_y
        self.width_x = width_x
        self.width_y = width_y 
        self.dense = dense 
        
    def update(self, zoom_x, zoom_y):
        self.width_x = self.width_x * zoom_x
        self.width_y = self.width_y * zoom_y
        
        






