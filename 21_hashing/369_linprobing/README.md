# Lesson 369 - Linear Probing 
## Using linear probing to represent a hashmap
### Description:
In this lesson we explore linear probing. This method is more deterministic, using an array to hold key-value pairs. 
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/21_hashing
$ mkdir build && cd build
$ cmake .. && make
$ cd build/369_linprobing
```
### Example:
Just run the command once built.
```bash
$ ./LinProbing
```
This should give you:
```
Adding 7 key/vals into a hashmap of size 5...TESTING: Entry added at 4
TESTING: Entry added at 0
TESTING: Entry added at 1
TESTING: Entry added at 2
TESTING: Entry added at 3
Showing value for key 0x14: 	523
Now deleting val for key 0x14
Key 0x14 does not exist.
```
If interested, the functions of note are located in src/linprobe.c:

```c
```
