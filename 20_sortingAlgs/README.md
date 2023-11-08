# Sorting Algorithms
## Description:
Fun stuff. we get to use sorting algorithms here. We will start with bubble sort (yawn) and tackle more complex things like radix sort and quick sort later.
## Structure
Most of the functionality will be in the src/sortAlgs* and include/sortAlgs* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/20_sortingAlgs
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./build/338_bubbleSort/
$ ./BubbleSort
```

