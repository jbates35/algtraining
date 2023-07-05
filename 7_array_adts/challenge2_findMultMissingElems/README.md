# Student challenge 2
## Finding multiple missing values in an array
### Description:
This exercise is meant to take in an array supplied by user. It then shows multiple missing values from the array.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge2_findMultMissingElems
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
```
$ ./challenge2 -x "4 3 6 2 9"
```
The missing value here would be 5, 7, 8. This would be stored in an array ADT.

Note: This program only works with positive integers.
Another note: If looking through code, the function of interest is 
```c
struct ArrayInt *findMissingVals(struct ArrayInt *arr);
```