# Lesson 141
## Permutations of strings
### Description:
This exercise is meant to take in string supplied by user. It then shows all the permutations that that string may exist in
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/8_strings/141_permutation
$ mkdir build && cd build
$ cmake ..
$ make
```
### Example:
Once built, there is one parameter for this program:
- x: The string
```
$ ./permutation -x "ASD"
```

The result should be:
```
ASD
ADS
SAD
SDA
DAS
DSA
```
Note: I didn't use string.h. The only functions that would have been useful from that are ```strlen``` and ```strcat```, but even then, it would have saved me like 2 lines of code.

Another note: If looking through code, the function of interest is 
```c
int permutation(const char* inputStr, const char *outputStr);
```