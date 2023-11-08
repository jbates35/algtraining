# Lesson 341 - Insertion Sort 
## Insertion sort on a whole array 
### Description:
The second most basic and useless of sorts, insertion sort.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/341_insertionSort
```
### Example:
Just run the command once built.
```bash
$ ./InsertionSort
```
This should give you:
```
Printing array...
5 15 20 25 40 45 50 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_insertionSort(int *A, int N);
```
