# Student challenge 7
## Finding the min and max values in a single scan of the array
### Description:
This exercise is meant to take in an array supplied by user. It then finds the min and max.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/7_array_adts/challenge7_findMinMaxSingleScan
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: Array values. Numbers to be stored in the array.
```
$ ./challenge7 -x "1 2 0 5 9 6""
```
The return should be:
```
Showing array vals:
1 2 0 5 9 6 

Minimum point is 0 at index 2
Maximum point is 9 at index 4
```
Note: the function of interest is:
```c
int minMax(struct ArrayInt *arr, struct Point* min, struct Point* max);
```

Last note: Time complexity should be O(n).