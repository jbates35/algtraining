# Lesson 222
## Doubly linked list
### Description:
This exercise is designed to provide practice working with doubly linked lists.

I will be experimenting a bit with encapsulating nodes in a linked list struct. I'd be a bit hesitant about using linked lists in embedded projects, as it relies on heap/dynamic memory. However, I think with due care linked lists could be useful, and therefore this module will hopefully have a bit of stuff hashed out that I can import later to a project.

### Setup: 
To use the program, rip the git, and then make a folder build in this folder. I.e.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 222_doublylinkedlist 
```
### Example:
Simply run the program, there are no arguments for this program
```bash
$ ./doubly
```
This will give you a result of:
```
Please select options:

        (1) Create list
        (2) Display list
        (3) Insert single node
        (4) Delete single node
        (5) Reverse list
        (0) Quit

Enter option: 1
Enter values for entries separated by space. I.e. '1 3 1 6'
1 3 2 6 9 4 10

Entries added!
Your list is:
[ 1 3 2 6 9 4 10 ]
```
Another note: If looking through code, the functions of interest are 
```c
void initList(DoublyLL **list);
void freeList(DoublyLL *list);
void appendNode(DoublyLL *list, int val);
void insertNode(DoublyLL *list, int val, int pos);
int deleteNode(DoublyLL *list, int pos);
void displayList(DoublyLL *list);
void reverseList(DoublyLL *list);
```
This can be found in src/dlinkedlist.c. 