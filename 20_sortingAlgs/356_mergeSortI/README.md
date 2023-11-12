# Lesson 356 - Merge sort  (Iteratively)
## Quick sort on a whole array 
### Description:
This merge sort will be done iteratively. Next lesson, we do it recursively, which is a bit weird as recursively is a bit easier.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/356_mergeSortI
```
### Example:
Just run the command once built.
```bash
$ ./MergeSortI
```
This should give you:
```
Printing array...
5 15 20 25 40 45 50 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_mergeSortI(int *A, int N);
```
