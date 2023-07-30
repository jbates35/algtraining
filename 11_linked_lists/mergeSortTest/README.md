# Merge sort test

### Description:
This is kinda just my own exercise to see if I can get merge-sort with a linked list to work!
To run this:
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd mergeSortTest 
```
### Example:
Optargs:
None
Run:
```bash
$ ./mergeSort
```
This will give you a result of:
```
Displaying list 1:
[ 1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17 ]
Displaying list after merge sort:
[ 1 1 3 5 9 9 10 10 12 13 14 15 17 19 21 24 25 ]
Displaying list 1:
[ 1 3 12 21 9 5 10 15 9 13 14 24 10 25 1 19 17 ]
Displaying list after bubble sort:
[ 1 1 3 5 9 9 10 10 12 13 14 15 17 19 21 24 25 ]

Now timing it with list of size 1E6
Time taken to execute mergeSortList: 19.097 ms
Time taken to execute sortList (bubble sort): 27477.154 ms
```
Lol, you really see O(nlog2_n) vs O(n^2) come into play here.