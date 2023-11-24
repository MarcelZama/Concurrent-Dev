Lab Six OpenMP:
Try out and get used to OpenMP.

Author:
Name: Marcel Zama
College Id: C00260146
Date 20/11/2023

Licence:

This project is safeguarded by the GNU General Public License (GPL) to promote the principles of open-source software and ensure that its benefits and freedoms are extended to all users.

See Licence for more details.

Installation:

1. Begin by installing GCC on your system.
2. Proceed to install Make for efficient project building.
3. Ensure that the pthread library is included in your system's library path.

Now, follow these steps in your terminal:

1. Open the terminal application.
2. Navigate to the specified folder.

# Examples of Map Pattern

Map is the simplest pattern.  It is embarrisingly parallel with no need for any data sharing between threads.

Two examples are included here with code showing how to get timing results demonstrating speedup.

## SAXPY

This is a standard algorithm used a lot in simulation.
It  stands for Single-precision y := alpha * x + y where alpha is a scalar and x and y are n-vectors. SAXPY is a combination of scalar multiplication and vector addition, and it’s very simple: it takes as input two vectors of 32-bit floats X and Y with N elements each, and a scalar value A. It multiplies each element X[i] by A and adds the result to Y[i]. There are Double and Complex data type versions as well - DAxpy, Caxpy, Zaxpy.

## Mandelbroit Set

The Mandelbrot set is a two-dimensional set with a relatively simple definition that exhibits great complexity, especially as it is magnified. It is popular for its aesthetic appeal and fractal structures. The set is defined in the complex plane as the complex numbers c c for which the function  f_{c}(z)=z^{2}+c  does not diverge to infinity when iterated starting at z = 0 z=0, i.e., for which the sequence f_{c}(0)}, f_{c}(f_{c}(0))}, etc., remains bounded in absolute value.

This set was first defined and drawn by Robert W. Brooks and Peter Matelski in 1978, as part of a study of Kleinian groups.[3] Afterwards, in 1980, Benoit Mandelbrot obtained high-quality visualizations of the set while working at IBM's Thomas J. Watson Research Center in Yorktown Heights, New York. [label](https://en.wikipedia.org/wiki/Mandelbrot_set)

s

For building the executable:

1. Execute the command "make" inside the terminal to construct the final executable.

For running the executable:/Applications/Discord.app

1.Employ the shell command ./ followed by the executable's name. Or double-click on it inside the directory folder.

Requirements:

A C++ compiler is required for executing the project.

This project is not specific to any platforms, should work on any platforms if the above requirement is fallowed.

Files:


TO DO:




