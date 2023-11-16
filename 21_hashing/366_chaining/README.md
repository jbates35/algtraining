# Lesson 366 - Chaining
## Using chaining to represent a hashmap
### Description:
In this lesson we explore chaining. This will use a linked list at an index decided by the last digit of each key. There are similarities between this and radix sort.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/21_hashing
$ mkdir build && cd build
$ cmake .. && make
$ cd build/366_chaining
```
### Example:
Just run the command once built.
```bash
$ ./Chaining
```
This should give you:
```
Value for key 20 is:	523
Value for key 2 is:	153
Value for key 95 is:	262
Value for key 23 is:	193
Value for key 66 is:	193
Unable to get key 66
```
If interested, the functions of note are located in src/chainhash.c:
```c
void chain_init(Chainhash **hashMap);
void chain_free(Chainhash *hashMap);
void chain_add(Chainhash *hashMap, int key, int val);
int chain_get(Chainhash *hashMap, int key, int *val);
int chain_del(Chainhash *hashMap, int key);
```
