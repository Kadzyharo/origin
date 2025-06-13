#include <iostream>
#include <string>

enum class Months
{
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

std::string getMonthName(int monthNumber)
{
    switch (static_cast<Months>(monthNumber))
    {
    case Months::January: return "January";
    case Months::February: return "February";
    case Months::March: return "March";
    case Months::April: return "April";
    case Months::May: return "May";
    case Months::June: return "June";
    case Months::July: return "July";
    case Months::August: return "August";
    case Months::September: return "September";
    case Months::October: return "October";
    case Months::November: return "November";
    case Months::December: return "December";
    default: return "Invalid";
    }
}

int main()
{
    int monthNumber{};
    
    do
    {
        std::cout << "Enter a month number or 0 to exit: ";
        std::cin >> monthNumber;

        if (monthNumber == 0)
        {
            std::cout << "Goodbye!" << '\n';
            break;
        }

        std::string monthName = getMonthName(monthNumber);
        if (monthName == "Invalid")
        {
            std::cout << "Invalid month number." << '\n';
        }
        else
        {
            std::cout << monthName << '\n';
        }

    } while (monthNumber != 0);

    return 0;
}
