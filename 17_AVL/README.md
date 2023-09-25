# Trees
## Description:
In this chapter, we will explore trees. This will be an interesting subject as trees start to get a little more complex and typically combine linked lists or array ADTs with queues.
## Structure
Most of the functionality will be in the src/queue* and include/queue* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/15_trees
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./299_binTree
$ ./binTree -x "1 3 -1 4 6 -1 8 -1 4"
```

Note: This will only have one folder as all the lessons are somewhat needed to make each other work.