# Lesson 246 - Infix to Postfix conversion v1
## Using a stack to convert an infix expression to postfix
### Description:
Calculators and other devices tend to analyze expressions using postfix. This allows for an expression to be analyzed without the need for brackets, thereby allowing an expression to be analyzed in a single pass through. 

This version will be without parantheses!
```bash
$ git clone https://github.com/jbates35/algtraining
$ cd ./algtraining/13_stack
$ mkdir build && cd build
$ cmake .. && make
$ cd 246_postfixConversion1
```
### Example:
No optargs for this one, just run the program
```bash
$ ./postfix1 -x "a + b * c - d / e"
```
This will give you a result of:
```
Postfix version of:
        a+b*c-d/e
is:
        abc*+de/-
```

If interested, the functions of note are located in 246_postfixConversion/main.c:
```c
int postfix(struct stack *st, char *infix);
```

p.s. Kinda regret using regex. Used it so it could be more easily expandable in the future, but it's messy!