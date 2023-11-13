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
```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_shellSort(int *A, int N);
```
