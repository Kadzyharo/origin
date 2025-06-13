#include <iostream>
#include <fstream>
#include <string>

class Address
{
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(std::string city, std::string street, int house, int apartment) : city(city), street(street), house(house), apartment(apartment) {}

    std::string get_output_address() const
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main()
{
    std::ifstream input("in.txt");
    std::ofstream output("out.txt");

    if (!input || !output)
    {
        std::cerr << "file opening error!" << std::endl;
        return 1;
    }

    int N;
    input >> N;
    input.ignore();

    Address** addresses = new Address*[N];

    for (int i = 0; i < N; ++i)
    {
        std::string city, street;
        int house, apartment;

        std::getline(input, city);
        std::getline(input, street);
        input >> house >> apartment;
        input.ignore();

        addresses[i] = new Address(city, street, house, apartment);
    }

    output << N << std::endl;

    for (int i = N - 1; i >= 0; --i)
    {
        output << addresses[i]->get_output_address() << std::endl;
    }

    for (int i = 0; i < N; ++i)
    {
        delete addresses[i];
    }
    delete[] addresses;

    std::cout << "The file out.txt successfully created." << std::endl;

    return 0;
}