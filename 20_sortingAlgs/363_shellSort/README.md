# Lesson 363 - Shell Sort
## Shell sort on a whole array 
### Description:
Shell sort is an okay-ish variation of insertSort which takes advantage of the fact that insertSort is very efficient when it is mostly sorted. It's an O(nlogn) algorithm. 

```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/362_shellSort
```
### Example:
Just run the command once built.
```bash
$ ./ShellSort
```
This should give you:
```
Printing array...
2 3 4 5 6 8 9 10 12 13 16 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_shellSort(int *A, int N);
```
