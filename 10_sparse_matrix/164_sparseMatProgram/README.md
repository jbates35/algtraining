# Lesson 152
## Upper Col-Major Single-Dimension Matrix
### Description:
This exercise is designed to provide practice for single dimension matrices, and in this one, it'll be upper col-major matrices.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/9_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 152_upSCMatrix 
```
### Example:
Once built, there are two parameters for this program:

-c Number of columns
-x Array of values

Such as:
```
$ ./upSCMatrix -c 4 -x "1 2 3 4 5 6 7 8 9 10"
```

With that, the result should be:
```
Showing array vals:
1 2 3 4 5 6 7 8 9 10 
Upper single-dimension col-major matrix:
[ 1, 2, 4, 7
  0, 3, 5, 8
  0, 0, 6, 9
  0, 0, 0, 10 ]


Enter a row to change:
3

Enter a col to change:
4

Enter a value to change it to:
11

New Matrix:
Upper single-dimension col-major matrix:
[ 1, 2, 4, 7
  0, 3, 5, 8
  0, 0, 6, 11
  0, 0, 0, 10 ]
```

Another note: If looking through code, the functions of interest are 
```c
void initSCUpTri(struct SCMatInt *mat, struct ArrayInt *arr, int cols);
void freeSCUpTri(struct SCMatInt *mat);
void setSCUpTri(struct SCMatInt *mat, int row, int col, int val);
void dispSCUpTri(struct SCMatInt *mat);
```
All of these are found in src/smatrixAdt.c.