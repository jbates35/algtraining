# Trees
## Description:
In this chapter, we will explore red-black trees. This tree uses red and black coloured nodes to create a set of rules that allow for fast sorting, inserting and an assurance that it's roughly log(n).
## Structure
Most of the functionality will be in the src/reblack* and include/redblack* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/18_RBTrees
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./326_RedBlackTrees
$ ./RedBlackTree
```

Note: This will only have one folder as all the lessons are somewhat needed to make each other work.