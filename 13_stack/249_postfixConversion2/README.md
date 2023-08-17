# Lesson 249 - Infix to Postfix conversion v2
## Using a stack to convert an infix expression to postfix
### Description:
Calculators and other devices tend to analyze expressions using postfix. This allows for an expression to be analyzed without the need for brackets, thereby allowing an expression to be analyzed in a single pass through. 

This version will be the whole shebang, exponents and brackets included.
```shell
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 249_postfixConversion2
```
### Example:
No optargs for this one, just run the program
```shell
$ ./postfix2 -x "((a+b)*c)-d^e^f"
```
This will give you a result of:
```
Postfix version of:
        ((a+b)*c)-d^e^f
is:
        ab+c*def^^-
```

If interested, the functions of note are located in 249_postfixConversion2/main.c:
```c
int postfix(struct stack *st, char *infix);
```