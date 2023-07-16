# Lesson 164
## Sparse Matrix Functionality
### Description:
This exercise is designed to provide practice for sparse matrices. Mostly, this program will give examples of what you can do with a sparse matrix.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/10_sparse_matrix
$ mkdir build && cd build
$ cmake .. && make
$ cd 164_sparseMatrix 
```
### Example:
There are no "optargs" for this program. I.e., just run the program with:
```
$ ./sparseMatrix
```

You will get some options as to what type of program you can run. For example:

```
Select options, or enter 0 to exit:
        (1) Enter one matrix and sort it
        (2) Add two matrices
```
Look at the main.c code to see a nice use of function pointers to pull this off!

Some functionality includes sorting the matrix's columns and rows. I.e. if you give it this set of entries:
```
| Row 0 | Col 1 | Val 20
| Row 1 | Col 0 | Val 20
| Row 0 | Col 0 | Val 40
| Row 0 | Col 3 | Val 40
| Row 2 | Col 2 | Val 2
```
It will sort it to:
```
| Row 0 | Col 0 | Val 40
| Row 0 | Col 1 | Val 20
| Row 0 | Col 3 | Val 40
| Row 1 | Col 0 | Val 20
| Row 2 | Col 2 | Val 2
```

Why do we need this? Well, a sorted sparse matrix (and not by the values, but by the matrix indices) makes iterating and operating on the struct arrays much faster. For the most part, we can keep our algorithms O(n+m) or O(n). A sorted matrix makes it much easier to print the matrix in a format that is readable, such as:

```
```

Another note: If looking through code, the functions of interest are 
```c
void initSparseMat(struct SparseMatrix *A, int rows, int cols);
void freeSparseMat(struct SparseMatrix *A);
void appendSparseMat(struct SparseMatrix *A, struct MatrixEntry entry);
struct MatrixEntry deleteSparseMat(struct SparseMatrix *A, int i);
struct MatrixEntry popBackSparseMat(struct SparseMatrix *A);
void sortSparseMat(struct SparseMatrix *A);
void printEntries(struct SparseMatrix *A);
void printMatrix(struct SparseMatrix *A);
struct SparseMatrix* addMatrices(struct SparseMatrix *A, struct SparseMatrix *B);
```
All of these are found in src/sparseMatrix.c.