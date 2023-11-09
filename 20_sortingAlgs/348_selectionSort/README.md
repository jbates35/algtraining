# Lesson 348 - Selection Sort 
## Selection sort on a whole array 
### Description:
The third most basic and useless of sorts, selection sort.
I cannot wait to move past these awful algorithms. But the completionist in me compels me to do this chapter.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/20_sortingAlgs
$ mkdir build && cd build
$ cmake .. && make
$ cd build/348_selectionSort
```
### Example:
Just run the command once built.
```bash
$ ./SelectionSort
```
This should give you:
```
Printing array...
5 15 20 25 40 45 50 

```
If interested, the functions of note are located in src/sortAlgs.c:

```c
void algs_selectionSort(int *A, int N);
```
