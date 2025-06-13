#include <iostream>
#include <string>

struct Address {
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int zipCode;
};

void printAddress(Address &address);

int main()
{
    Address address1 = {"Moscow", "Arbat", 12, 8, 123456};
    Address address2 = {"Izhevsk", "Pushkina", 59, 143, 953769};
    
    printAddress(address1);
    std::cout << '\n';
    printAddress(address2);

    return 0;
}

void printAddress(Address &address)
{
    std::cout << "City: " << address.city << "\n";
    std::cout << "Street: " << address.street << "\n";
    std::cout << "House Number: " << address.houseNumber << "\n";
    std::cout << "Apartment Number: " << address.apartmentNumber << "\n";
    std::cout << "ZIP Code: " << address.zipCode << "\n";
}