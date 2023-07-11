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
$ ./challenge1 -x "ASDF"
```



Another note: If looking through code, the function of interest is 
```c
int permutation(const char* inputStr, const char *outputStr);
```