# Mandelbrot Set Visualization in C

This project was my first step in learning C. It prints the Mandelbrot set and gradually zooms in to reveal more detail. Before writing the code in C, I did some prototyping in Python to understand the basics.

## Project Overview

The program generates the Mandelbrot set, a famous fractal pattern, and zooms in as it runs. This zoom feature highlights the intricate details of the set, showing how it looks the same at every level.

### Key Learning Points

- **Stack vs Heap Memory**: I learned how memory is managed in C, specifically how variables are stored on the stack while dynamic data (like arrays) are stored on the heap using `malloc` and `free`.
  
- **Pointers**: I used pointers to modify arrays, which was key to updating the display as the program zoomed in on the Mandelbrot set. This allowed me to rethink arrays as continuous blocks of memory addresses, and I began using pointer arithmetic to access and manipulate data more efficiently.

## How to Run

To compile the project with multiple source files (`main.c`, `axis.c`, and `helper.c`), use the following command:

```bash
gcc -o mandelbrot main.c axis.c helper.c
./mandelbrot
```

## Adjustable Parameters

The program has three major constants that control the behavior of the Mandelbrot set visualization:

- **`ZOOM_iter`**: This controls how many iterations of zooming will be performed. A higher value will zoom in more over time.
- **`MAX_Iter`**: This defines the maximum number of iterations used to calculate each point in the Mandelbrot set. A higher value makes the fractal more detailed but increases computation time.
- **`DENSE`**: This controls the resolution of the grid used to render the Mandelbrot set. Higher values increase the density of the points and make the image more detailed.

### How to Modify Parameters

These constants are defined in the source code and can be modified directly by editing the corresponding values in `main.c` (or another appropriate file):

```c
#define ZOOM_iter 100  // Number of zoom iterations
#define MAX_Iter 1000  // Maximum iterations per point
#define DENSE 500      // Density of points in the grid
```
