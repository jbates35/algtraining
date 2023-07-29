# Student Challenge 2
## Find intersection of two lists
### Description:
This exercise is meant to see if we can use our linked list library to find the intersection of two lists. I.e., if we see the lists start having common nodes.
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 227_studentChallenge2_intersect 
```
### Example:
No optargs for this one, just run the program
```bash
$ ./intersect
```
This will give you a result of:
```
Displaying list 1:
[ 1 3 6 2 10 14 152 193 ]
Displaying list 2:
[ 2 6 2 9 10 14 152 193 ]

Intersecting nodes are:
[ 10 14 152 193 ]
```
This just mean that's it has detected the last four nodes as having common pointers between the two lists, which is true.

I managed to use two array stacks and pop them until the lists don't match. This way, the problem was done with an O(n) solution instead of O(n^2). Though, this is more like O(4*n) lol. 