# Lesson 151
## Upper Row-Major Single-Dimension Matrix
### Description:
This exercise is designed to provide practice for single dimension matrices, and in this one, it'll be lower col-major matrices.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/9_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 151_upSRMatrix 
```
### Example:
Once built, there are two parameters for this program:

-r Number of rows
-x Array of values

Such as:
```
$ ./upSRMatrix -r 4 -x "1 2 3 4 5 6 7 8 9 10"
```

With that, the result should be:
```

Showing array vals:
1 2 3 4 5 6 7 8 9 10 
Upper single-dimension row-major matrix:
[ 1, 2, 3, 4
  0, 5, 6, 7
  0, 0, 8, 9
  0, 0, 0, 10 ]


Enter a row to change:
2

Enter a col to change:
2

Enter a value to change it to:
11

New Matrix:
Upper single-dimension row-major matrix:
[ 1, 2, 3, 4
  0, 11, 6, 7
  0, 0, 8, 9
  0, 0, 0, 10 ]
```

Another note: If looking through code, the functions of interest are 
```c
void initSRUpTri(struct SRMatInt *mat, struct ArrayInt *arr, int rows);
void freeSRUpTri(struct SRMatInt *mat);
void setSRUpTri(struct SRMatInt *mat, int row, int col, int val);
void dispSRUpTri(struct SRMatInt *mat);
```
All of these are found in src/smatrixAdt.c.