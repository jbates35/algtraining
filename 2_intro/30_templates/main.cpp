#include <iostream>

template <typename T>
class Arithmetic 
{
private:
    T a;
    T b;

public:
    Arithmetic(T locA, T locB) : a { locA }, b { locB }
    {}
    ~Arithmetic()
    {}
    
    T add()
    {
        return a + b;
    }

    T substract()
    {
        return a - b;
    }

    T multiply()
    {
        return a * b;
    }

    T divide()
    {
        return a / b;
    }
};


int main()
{
    Arithmetic<float> arith(3.5, 4.8);
    
    float sum = arith.add();
    float diff = arith.substract();
    float prod = arith.multiply();
    float div = arith.divide();

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;
    std::cout << "Divisor: " << div << std::endl;

    return 0;
}