# DSA
## Exercises while following Abdul Bari's course on Udemy

This is basically where I've been keeping my work for working on my data structures & algorithm skills. My workflow has mostly been:
- Study a couple videos.
- Try to work out the problems on my own
- Verify and test

I've mostly tried to go from the white board exercises to coding them, as I think that's good practice as well. I have typically refrained from trying to look at how someone specifically coded it and copying it unless I'm just *really* stuck. This rarely happened though.

No chatgpt or copilot was used for this either. I'm not at all opposed to them, but that removed some of the struggle that helps me leran, so I wanted to avoid those.

You can enter most folders (I'd say past folder 6 or 7) and you will see a general CMakeLists.txt and instructions on how to build and test the programs yourself.

The tree for this program is:
```
.
├── 10_sparse_matrix
│   ├── 164_sparseMatProgram
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── helpFuncs.h
│   │   └── sparseMatrix.h
│   ├── README.md
│   └── src
│       └── sparseMatrix.c
├── 11_linked_lists
│   ├── 175_showLinkedList
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 177_showRecursLinkedList
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 180_countAndSum
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 182_max
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 184_search
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 191_insert
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 193_delete
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 197_removeDuplicates
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 201_reverseList
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 204_mergelists
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 210_circularlists
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 222_doublylinkedlist
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 226_studentChallenge1_findMiddle
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 227_studentChallenge2_intersect
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── dlinkedlist.h
│   │   ├── helpFuncs.h
│   │   ├── linkedlist.h
│   │   └── rlinkedlist.h
│   ├── mergeSortTest
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   ├── README.md
│   │   └── valList.h
│   ├── README.md
│   └── src
│       ├── dlinkedlist.c
│       ├── linkedlist.c
│       └── rlinkedlist.c
├── 12_sparseMatWithLL
│   ├── 228_sparseMatLL
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 229_polynomial
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── helpFuncs.h
│   │   ├── poly.h
│   │   └── sparseMatrix.h
│   ├── README.md
│   └── src
│       ├── poly.c
│       └── sparseMatrix.c
├── 13_stack
│   ├── 234_stackArray
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 237_stackLL
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 241_parentheses
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 246_postfixConversion1
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 249_postfixConversion2
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 252_postfixEvaluation
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── helpFuncs.h
│   │   ├── stackarr.h
│   │   └── stackll.h
│   ├── README.md
│   └── src
│       ├── stackarr.c
│       └── stackll.c
├── 14_queues
│   ├── 257_queue
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 261_circularQueue
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 263_queueLL
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   ├── queue.h
│   │   └── queueLL.h
│   ├── README.md
│   └── src
│       ├── queue.c
│       ├── queueCircular.c
│       └── queueLL.c
├── 15_trees
│   ├── 299_binTree
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── arrayAdt.h
│   │   ├── binTree.h
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   └── stackarr.h
│   ├── README.md
│   └── src
│       ├── arrayAdt.c
│       ├── binTree.c
│       ├── queueCircular.c
│       └── stackarr.c
├── 16_BST
│   ├── 305_createBST
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 307_deleteNodesBST
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 309_BSTfromPO
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── arrayAdt.h
│   │   ├── binTree.h
│   │   ├── bst.h
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   └── stackarr.h
│   ├── README.md
│   └── src
│       ├── arrayAdt.c
│       ├── binTree.c
│       ├── bst.c
│       ├── queueCircular.c
│       └── stackarr.c
├── 17_AVL
│   ├── 317_AVLTrees
│   │   ├── arrayOfInts.h
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   ├── MakeArray.py
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── arrayAdt.h
│   │   ├── avl.h
│   │   ├── binTree.h
│   │   ├── bst.h
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   └── stackarr.h
│   ├── README.md
│   └── src
│       ├── arrayAdt.c
│       ├── avl.c
│       ├── binTree.c
│       ├── bst.c
│       ├── queueCircular.c
│       └── stackarr.c
├── 18_RBTrees
│   ├── 326_RedBlackTrees
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   ├── MakeArray.py
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── arrayAdt.h
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   ├── redblack.h
│   │   └── stackarr.h
│   ├── README.md
│   └── src
│       ├── arrayAdt.c
│       ├── queueCircular.c
│       ├── redblack.c
│       └── stackarr.c
├── 19_heap
│   ├── 329_insertHeap
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 332_sortHeap
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── heapADT.h
│   │   └── heap.h
│   ├── README.md
│   └── src
│       ├── heapADT.c
│       └── heap.c
├── 20_sortingAlgs
│   ├── 338_bubbleSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 341_insertionSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 348_selectionSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 353_quickSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 356_mergeSortI
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 358_mergeSortR
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 360_countSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 362_radixSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 363_shellSort
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── helpFuncs.h
│   │   └── sortAlgs.h
│   ├── README.md
│   ├── SpeedTest
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   ├── make_array.py
│   │   └── README.md
│   └── src
│       └── sortAlgs.c
├── 21_hashing
│   ├── 366_chaining
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 369_linprobing
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── chainhash.h
│   │   ├── helpFuncs.h
│   │   └── linprobe.h
│   ├── README.md
│   └── src
│       ├── chainhash.c
│       └── linprobe.c
├── 22_graphs
│   ├── 377_breadthFS
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 379_depthFS
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 384_prims
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 388_kruskals
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── graphs.h
│   │   ├── heap.h
│   │   ├── helpFuncs.h
│   │   ├── queueCircular.h
│   │   └── stackarr.h
│   ├── README.md
│   └── src
│       ├── graphs.c
│       ├── heap.c
│       ├── queueCircular.c
│       └── stackarr.c
├── 2_intro
│   ├── 30_templates
│   │   ├── CMakeLists.txt
│   │   ├── main.cpp
│   │   └── README.md
│   ├── 4_arrayBasics
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   └── 6_structs
│       ├── CMakeLists.txt
│       └── main.cpp
├── 5_recursion
│   ├── 61_sumNaturalNubers
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── 63_factorial
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── 65_powers
│   │   ├── CMakeLists.txt
│   │   ├── main
│   │   └── main.c
│   ├── 67_taylor
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── oldmain.c
│   ├── 69_taylor_2
│   │   ├── CMakeLists.txt
│   │   ├── loopVersion.c
│   │   └── recursVersion.c
│   ├── 72_fibonacci
│   │   ├── CMakeLists.txt
│   │   ├── main
│   │   ├── main.c
│   │   ├── main_memoization.c
│   │   ├── null_main_nonrecurs.c
│   │   └── null_main_recurswithpointers.c
│   ├── 74_ncr
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   ├── old_main.c
│   │   └── tree_main.c
│   └── 76_tower_of_hanoi
│       ├── CMakeLists.txt
│       └── main.c
├── 6_arrays
│   ├── 82_staticvsdynamic
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── 83_staticvsdynamic
│   │   ├── CMakeLists.txt
│   │   ├── main
│   │   └── main.c
│   ├── 85_increase_size
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── 87_2d_array
│   │   ├── CMakeLists.txt
│   │   ├── main
│   │   └── main.c
│   └── general_practice
│       ├── CMakeLists.txt
│       └── main.c
├── 7_array_adts
│   ├── 95_array_Adt
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── array_adt_script
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── arrayAdtSort.c
│   │   ├── arrayAdtSort.h
│   │   ├── CMakeLists.txt
│   │   └── main.c
│   ├── array_adt_script_2
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── sampleArrays.h
│   ├── challenge1_findMissingElems
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge2_findMultMissingElems
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge3_findDupEntries
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge4_dupEntiresHashing
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge5_findSumPairsUnsorted
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge6_findSumPairsSorted
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   ├── challenge7_findMinMaxSingleScan
│   │   ├── arrayAdt.c
│   │   ├── arrayAdt.h
│   │   ├── CMakeLists.txt
│   │   ├── helpFuncs.h
│   │   ├── main.c
│   │   └── README.md
│   └── README.md
├── 8_strings
│   └── 141_permutation
│       ├── CMakeLists.txt
│       ├── main.c
│       └── README.md
├── 9_matrices
│   ├── 143_diagMatrix
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 145_lowSRMatrix
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 148_lowSCMatrix
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 151_upSRMatrix
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── 152_upSCMatrix
│   │   ├── CMakeLists.txt
│   │   ├── main.c
│   │   └── README.md
│   ├── CMakeLists.txt
│   ├── include
│   │   ├── arrayAdt.h
│   │   ├── helpFuncs.h
│   │   ├── matrixAdt.h
│   │   └── smatrixAdt.h
│   ├── README.md
│   └── src
│       ├── arrayAdt.c
│       ├── matrixAdt.c
│       └── smatrixAdt.c
└── README.md

131 directories, 403 files

```
