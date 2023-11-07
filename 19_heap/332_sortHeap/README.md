# Lesson 332 - Heap sort 
## Using heap binary trees for sorting 
### Description:
Heap data structures are a specialized tree data structure for storing data. We will be using a heap data structure for sorting
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/18_RBTrees
$ mkdir build && cd build
$ cmake .. && make
$ cd 332_sortHeap 
```
### Example:
Just run the command once built.
```bash
$ ./HeapSort
```
This should give you:
```
Sorting heap with vals:
1 3 5 7 9 10 8 6 4 2 
1 2 3 4 5 6 7 8 9 10 
```
Should be roughly O(nlogn) for time complexity. Space complexity is O(1) :)

If interested, the functions of note are located in src/heap.c:
```c
void heap_sort(int A[], int N);
```
