# Lesson 145
## Lower Row-Major Single-Dimension Matrix
### Description:
This exercise is designed to provide practice for single dimension matrices, and in this one, it'll be lower row-major matrices.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/9_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 145_lowSRMatrix 
```
### Example:
Once built, there are two parameters for this program:

-r Number of rows
-x Array of values

Such as:
```
$ ./lowSRMatrix -r 3 -x "1 3 5 1"
```

With that, the result should be:
```
Showing array vals:
1 3 5 1 
Lower matrix:
[ 1, 0, 0
  3, 5, 0
  1, 0, 0 ]


Enter a row to change:
3

Enter a col to change:
3

Enter a value to change it to:
10

New Matrix:
Lower matrix:
[ 1, 0, 0
  3, 5, 0
  1, 0, 10 ]
```

Another note: If looking through code, the functions of interest are 
```c
void initSRLowTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows);
void freeSRLowTri(struct SRMatInt *mat);
void setSRLowTri(struct SRMatInt *mat, int row, int col, int val);
void dispSRLowTri(struct SRMatInt *mat);
```
All of these are found in src/smatrixAdt.c.