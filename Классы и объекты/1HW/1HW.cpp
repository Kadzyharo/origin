#include <iostream>

class Calculator
{
private:
    double num1{};
    double num2{};
    
public:
    Calculator(double num1t, double num2t)
    {
        set_num1(num1t);
        set_num2(num2t);
    }

    bool set_num1(double num1t)
    {
        if (num1t != 0)
        {
            this->num1 = num1t;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool set_num2(double num2t)
    {
        if (num2t != 0)
        {
            this->num2 = num2t;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    double add()
    {
        return num1 + num2;
    }
    double multiply()
    {
        return num1 * num2;
    }
    double subtract_1_2()
    {
        return num2 - num1;
    }
    double subtract_2_1()
    {
        return num1 - num2;
    }
    double divide_1_2()
    {
        return num1 / num2;
    }
    double divide_2_1()
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