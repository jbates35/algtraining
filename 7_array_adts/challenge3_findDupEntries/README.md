# Student challenge 13
## Finding duplicate values in an array
### Description:
This exercise is meant to take in an array supplied by user. It then finds duplicate entries.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge3_findDupEntries
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
```
$ ./challenge3 -x "4 2 5 3 4 2 6"
```
The duplicate and shown values here would be 2 and 4. This would be stored in an array ADT.

Note: This program only works with positive integers.
Another note: If looking through code, the function of interest is 
```c
struct ArrayInt *findDuplicates(struct ArrayInt *arr);
```