# Student Challenge 1
## Find middle of linked list
### Description:
This exercise is meant to see if we can use our linked list library to find the middle of a linked list. Note that this means the middle element position wise, not the element with the value closest to the mean.
### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 226_studentChallenge1_findMiddle 
```
### Example:
There is one optarg for this program, which is:
x - List of elements to make list with
```bash
$ ./findMiddle -x "1 3 1 9 6 2 0 3 1 13"
```
This will give you a result of:
```
Displaying list:
[ 1 3 1 9 6 2 0 3 1 13 ]
Middle value is 2 at position 5
```