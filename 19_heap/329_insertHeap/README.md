# Lesson 329 - Heap insert
## Using heap binary trees for inserting
### Description:
Heap data structures are a specialized tree data structure for storing data. We will be coding a max heap tree in this activity.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/18_RBTrees
$ mkdir build && cd build
$ cmake .. && make
$ cd 326_RedBlackTrees
```
### Example:
Just run the command once built.
```bash
$ ./HeapInsert
```
This should give you:
```
Adding 1
Heap: 1 , 

Adding 4
Heap: 4 , 1 

Adding 2
Heap: 4 , 1 2 , 

Adding 6
Heap: 6 , 4 2 , 1 

Adding 10
Heap: 10 , 6 2 , 1 4 

Adding 9
Heap: 10 , 6 9 , 1 4 2 

Adding 3
Heap: 10 , 6 9 , 1 4 2 3 , 

Adding 14
Heap: 14 , 10 9 , 6 4 2 3 , 1 

Adding 16
Heap: 16 , 14 9 , 10 4 2 3 , 1 6 

Adding 15
Heap: 16 , 15 9 , 10 14 2 3 , 1 6 4 

```
This is what's expected. The way I set this up is 15 and 9 would be under 16, 10 14 would be under 15, 1 6 would be under 10, so on and so forth.

If interested, the functions of note are located in src/heap.c:
```c
void heap_init(HeapArray *heap, int size);
void heap_free(HeapArray *heap);
void heap_print(HeapArray *heap);
void heap_insert(HeapArray *heap, int val);

```
