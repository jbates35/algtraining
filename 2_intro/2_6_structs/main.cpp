#include <iostream>
#include <stdio.h>

struct Rectangle
{
    int length;
    int breadth;
    char x;

    int calculate() {
        return length * breadth;
    }
};


int main(void)
{

    struct Rectangle r1;
    r1.length = 5;
    r1.breadth = 7;
    std::cout << "Area of rect is ... " << r1.calculate() << std::endl;
    std::cout << "Size of this struct is " << sizeof(r1) << std::endl;
}