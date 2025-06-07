#include <iostream>

class Counter
{
    int value{};
    
public:
    Counter() : value(1){}
    Counter(int startValue) : value(startValue){}

    void decrement()
    {
        value--;
    }
    void increment()
    {
        value++;
    }
    int getValue() const
    {
        return value;
    }
};

int main()
{
    char choice{};
    int startValue{};
    Counter counter;

    std::cout << "Do you want to specify the initial counter value? Enter yes or no: ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        std::cout << "Enter the initial counter value: ";
        std::cin >> startValue;
        counter = Counter(startValue);
    }

    while (true)
    {
        std::cout << "Enter the command ('+', '-', '=' or 'x'): ";
        std::cin >> choice;

        if (choice == '+')
        {
            counter.increment();
        }
        else if (choice == '-')
        {
            counter.decrement();
        }
        else if (choice == '=')
        {
            std::cout << counter.getValue() << std::endl;
        }
        else if (choice == 'x')
        {
            std::cout << "The program has completed" << std::endl;
            break;
        }
    }
    
    return 0;
}