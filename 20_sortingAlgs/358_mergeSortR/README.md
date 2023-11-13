# Lesson 358 - Merge sort (Recursively)
## Merge sort on a whole array 
### Description:
This merge sort will be done recursively.  
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/358_mergeSortR
```
### Example:
Just run the command once built.
```bash
$ ./MergeSortR
```
This should give you:
```
Printing array...
5 15 20 25 40 45 50 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_mergeSortR(int *A, int N);
```
