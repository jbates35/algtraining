# Lesson 143
## Diagonal Matrix
### Description:
This exercise is an introduction to matrices, starting with the diagonal matrix.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/8_strings/143_diagMatrix
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:

```
$ ./diagMatrix -x "1 3 5 7"
```

The result should be:
```
Showing array vals:
1 3 5 7 

Matrix:
        [ 1, 0, 0, 0
          0, 3, 0, 0
          0, 0, 5, 0
          0, 0, 0, 7 ]
```

Another note: If looking through code, the functions of interest are 
```c
int initMat(struct MatrixInt *mat, int rows, int cols);
int freeMat(struct MatrixInt *mat);
void displayMat(struct MatrixInt *mat);
void setMatDiag(struct MatrixInt *mat, struct ArrayInt *arr);
```
All of these are found in src/matrixAdt.c.