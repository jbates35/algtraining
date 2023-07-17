# Linked Lists
## Description:
This will be the subdirectory for linked lists. This should end up being a fairly large subdirectory.

Linked-lists are one way to get around C's statically sized arrays. The essential idea is that you have a struct with both a value, and the pointer to the next node in the linked list.

I'm not sure how much they get used in embedded, but they're almost definitely safer than constantly using malloc and realloc on an array, which can lead to memory leaks if not done carefully.

## Structure
Most of the functionality will be in linkedlist.h and linkedlist.c. This will allow me to more easily port my code to other projects. The numbered folders such as "175_showLinkedList" will show the implementation of my linkedlist module.

## Usage
Much like the last few folders, this will have a root CMakeLists.txt that allows one to simply make a build folder and then make all the subprograms at once. I.e.:

```
git clone https://github.com/jbates35/algtraining
cd ./algtraining/11_linked_lists/
mkdir build
cd build
cmake ..
make
```

Then to run a program, go:

```
cd 175_showLinkedList
./showLinkedList -x "5 9 10 4 2 11"
```