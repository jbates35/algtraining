# Lesson 360 - Count Sort 
## Count sort on a whole array 
### Description:
This will be count sort, which somewhat gets into bin/bucket approaches to sorting.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/360_countSort
```
### Example:
Just run the command once built.
```bash
$ ./CountSort
```
This should give you:
```
Printing array...
3 3 6 6 6 8 9 10 12 15 
```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_countSort(int *A, int N);
```
