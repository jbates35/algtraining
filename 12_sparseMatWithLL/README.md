# A couple challenges
## Description:
This will be the subdirectory for a couple challenges that combine the last two chapters, sparse matrices with linked lists.

## Structure
Most of the functionality will be in linkedlist.h and sparseMatrix.c. We're going to adjust both of these to fit the mold of these problems in this chapter.
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```
git clone https://github.com/jbates35/algtraining
cd ./algtraining/12_spareMatWithLL
mkdir build
cd build
cmake ..
make
```

Then to run a program, go:

```
$ cd 228_sparseMatLL
$ ./sparseMatLL
```