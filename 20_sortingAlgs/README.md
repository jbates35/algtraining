# Heap Data Trees
## Description:
In this chapter, we will be exploring heap data trees. As far as I can tell, the biggest use case this has is in preparation for the graphs chapter.
## Structure
Most of the functionality will be in the src/heap* and include/heap* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/19_heap
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./HeapInsert
$ ./HeapInsert
```

Note: This will only have one folder as all the lessons are somewhat needed to make each other work.
