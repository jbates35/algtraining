# Lesson 234 - Parenthesis matching
## Using a stack to check the integrity of parentheses in an expression
### Description:
This exercise is meant to use stacks to check if an expression has the correct order of parentheses. This exercise is more of an algorithmic exercise as opposed to a data structures exercise, as we've already made our data structure functionality in previous exercises.
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 241_parentheses
```
### Example:
No optargs for this one, just run the program
```bash
$ ./parenth -x "((x+4)(x+6) + x^2)"
```
This will give you a result of:
```
Analyzing expression: ((x+4)(x+6) + x^2)
Parentheses match
```

If you put in:
```bash
$ ./parenth -x "((x+4)(x+6) + x^2"
```
This will give you a result of:
```
Analyzing expression: ((x+4)(x+6) + x^2
Parentheses don't match
```

If interested, the functions of note are located in 241_parnetheses/main.c:
```c
int parenthMatch(struct stack *st, char *exp);
```