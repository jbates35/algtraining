# Lesson 362 - Radix Sort
## Radix sort on a whole array 
### Description:
Radix sort takes a bit of an interesting approach to sorting, where we don't compare values but instead put them into their buckets by ascending order of digits.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/362_radixSort
```
### Example:
Just run the command once built.
```bash
$ ./RadixSort
```
This should give you:
```
```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_radixSort(int *A, int N);
```
