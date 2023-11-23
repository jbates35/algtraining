# Graphs
## Description:
Graphs are used for various things such as network routing, machine learning, and image processing. They require vertices (nodes) and edges (links) in various forms.
## Structure
Most of the functionality will be in the src/graphs.c and include/graphs.h files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/22_graphs
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./build/377_breadthFS/
$ ./BFS
```

