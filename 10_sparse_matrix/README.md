# Sparse Matrices
## Description: 
This root folder will contain all the files pertaining to the <i>sparse</i> matrix section of the DSA course.

The important functionality will be in:
```
├── include
│   └── sparseMatrix.h
└── src
    └── sparseMatrix.c
```
And then the numbered folders will contain the implementation of the sparseMatrix functions. Why am I doing it this way? I could see myself using sparse matrices in embedded applications, so I would enjoy having a nice juicy include/src file I could include later down the road. 

Sparse matrices can be executed in a few different ways. The way I chose to do it is having a struct, MatrixEntry, that contains the column, row, and value for each entry. Afterwards, there's another struct, SparseMatrix which contains the dimensions of the matrix, the number of elements, the size of the matrix (for memory allocation purposes), and then an array of MatrixEntry structs. Of course, if I were doing this in an embedded application, I would use a statically allocated array of MatrixEntries, as dynamic memory allocation is generally good to be avoided on microcontrollers.

All the programs can be built at once. The way you do this is you make the build folder in this folder. I.e., in linux bash:
```
git clone https://github.com/jbates35/algtraining
cd ./algtraining/10_sparse_matrix/
mkdir build
cd build
cmake ..
make
```
From here you'd go, for instance:
```
cd 164_sparseMatProgram
./addMatrices
```

For particular instructions on how to run each program, I will have a README.md in each project folder that will explain which options/parameters to pass to run the function.
