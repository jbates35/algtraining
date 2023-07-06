# Student challenge 4
## Finding duplicate values in an unsorted array using hashtable
### Description:
This exercise is meant to take in an array supplied by user. It then finds duplicate entries.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge4_findDupEntries
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
```
$ ./challenge4 -x "1 5 3 3 49 47 3 59 49 60 3 60"
```
The duplicate and shown values here would be 3, 49 and 60. This would be stored in an array ADT.

Note: This program only works with positive integers.

Another note: If looking through code, the function of interest is 
```c
struct ArrayInt *findDuplicates(struct ArrayInt *arr);
```

Last note: Time complexity should be O(2n) = O(n)