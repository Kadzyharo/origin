#include <iostream>

class Calculator
{
    double num1{};
    double num2{};
    
public:
    Calculator(double num1t, double num2t) : num1(num1t), num2(num2t){}
    
    double add() const
    {
        return num1 + num2;
    }
    double multiply() const
    {
        return num1 * num2;
    }
    double subtract_1_2() const
    {
        return num2 - num1;
    }
    double subtract_2_1() const
    {
        return num1 - num2;
    }
    double divide_1_2() const
    {
        return num1 / num2;
    }
    double divide_2_1() const
    {
        return num2 / num1;
    }
};

int main()
{
    while (true)
    {
        double num1t{};
        double num2t{};

        std::cout << "Enter num1: " << std::endl;
        std::cin >> num1t;
        std::cout << "Enter num2: " << std::endl;
        std::cin >> num2t;

        if (num1t == 0 || num2t == 0)
        {
            std::cout << "Wrong number!" << std::endl;
            continue;
        }

        Calculator calc(num1t, num2t);

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_2_1() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_1_2() << std::endl;
    }
    
    return 0;
}