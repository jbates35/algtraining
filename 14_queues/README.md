# Queue
## Description:
In this chapter, we will explore and program queues. FIFO! Unlike stacks, queues are a first in and first out system. In my experience with work and embedded, I find queues to be quite common.
## Structure
Most of the functionality will be in the src/queue* and include/queue* files. 
## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```shell
git clone https://github.com/jbates35/algtraining
cd ./algtraining/13_stack
mkdir build
cd build
cmake ..
make
```
Then to run a program, go:

```
$ cd ./257_queue
$ ./queue -x "1 3 5 2 6 7" -s 5
```