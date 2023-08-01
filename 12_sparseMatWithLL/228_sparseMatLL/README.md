# Student Challenge 1
## Sparse matrix with linked lists
### Description:
This exercise is meant to see if we can use our linked list library to represent a sparse matrix. This will require changing the value type in the linked list nodes to the sparse matrix node.
```
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/11_linked_list
$ mkdir build && cd build
$ cmake .. && make
$ cd 228_sparseMatLL
```
### Example:
No optargs for this one, just run the program
```bash
$ ./sparseMatLL
```
This will give you a result of:
```

Single matrix only.
Enter number of rows:
3

Enter number of columns:
3

Enter number of entries. Note the bounds has to be between 1 and 9 (inclusive):
3

Great! Generating a sparse matrix of 3 rows and 3 columns.

Please enter the information for 3 values:

Enter row:
1

Enter column:
1

Enter value:
1

Appending matrix with entry for row 1, column 1, with value 1

Enter row:
2

Enter column:
2

Enter value:
2

Appending matrix with entry for row 2, column 2, with value 2

Enter row:
0

Enter column:
0

Enter value:
3

Appending matrix with entry for row 0, column 0, with value 3

Displaying matrix:

3       0       0
0       1       0
0       0       2
```
