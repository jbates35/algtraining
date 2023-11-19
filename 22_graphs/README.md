# Hashing Techniques 
## Description:
Hashing is an effective way of storing and searching through data. Python can nearly get a hashing algorithm near O(1), through the use of quadratic probing and careful collision detection algorithms.
## Structure
Most of the functionality will be in the src/hashing* and include/hashing* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/21_hashing
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./build/366_chaining/
$ ./Chaining
```

