# Lesson 252 - Evaluation of post fix expression
## Using a stack to evaluate a post fix expression
### Description:
Calculators and other devices tend to analyze expressions using postfix. This allows for an expression to be analyzed without the need for brackets, thereby allowing an expression to be analyzed in a single pass through. 

This program will evaluate a post fix expression.
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
$ ./postfixsolve -x "10 5 3 * + 10 2 / - 5 2 ^ +"
```
This will give you a result of:
```
Answer for expression:
10 5 3 * + 10 2 / - 5 2 ^ +

is:
45
```

If interested, the functions of note are located in 252_postfixEvaluation/main.c:
```c
int solve(struct stack *st);
```