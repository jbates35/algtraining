# Student challenge 1
## Finding the missing value in an array
### Description:
This exercise is meant to take in an array supplied by user. It then shows a single missing value from the array. It'd be the first missing value.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge1_findMissingElems
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
```
$ ./challenge1 -x "4 3 6 2"
```
The missing value here would be 5, which would be returned.

Note: This program only works with positive integers.
Another note: If looking through code, the function of interest is 
```c
int findMissingVal(struct ArrayInt *arr)
```