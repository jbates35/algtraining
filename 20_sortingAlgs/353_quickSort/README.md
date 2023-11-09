# Lesson 353 - Quick Sort 
## Quick sort on a whole array 
### Description:
Now we get into the O(nlogn) sort algs. Quick sort is where you compare the elements to the first element (pivot element) until you find the place it should go. Python uses a variation of this method I believe.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/353_quickSort
```
### Example:
Just run the command once built.
```bash
$ ./QuickSort
```
This should give you:
```
Printing array...
5 15 20 25 40 45 50 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_quickSort(int *A, int N);
```
