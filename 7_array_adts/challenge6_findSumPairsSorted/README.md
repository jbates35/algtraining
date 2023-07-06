# Student challenge 6
## Finding summed pairs in a sorted array
### Description:
This exercise is meant to take in an array supplied by user. It then finds which two values equals a summed value.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge5_findSumPairsUnsorted
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
- s: Sum. Desired sum to have the two values equal to.
```
$ ./challenge6 -x "1 2 4 6 9 10 10" -s 11
```
The result of executing this app looks like:

```
Showing array vals:
1 2 4 6 9 10 10 

Pairs found!! Displaying pairs!
Pair 0: <1, 10>
Pair 1: <2, 9>
```

Note: This program only works with positive integers.

Another note: If looking through code, the function of interest is 
```c
struct ArrayPairs *findSumPairs(struct ArrayInt *arr, int sum);
```

Last note: Time complexity should be O(n).