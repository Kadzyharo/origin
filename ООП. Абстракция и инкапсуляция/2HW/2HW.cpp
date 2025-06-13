#include <iostream>
#include <fstream>

class Address
{
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(std::string city, std::string street, int house, int apartment) : city(city), street(street), house(house), apartment(apartment){}

    std::string get_output_address() const
    {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }

    std::string get_city() const
    {
        return city;
    }
};

void sort(Address** addresses, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (addresses[j]->get_city() > addresses[j + 1]->get_city())
            {
                std::swap(addresses[j], addresses[j + 1]);
            }
        }
    }
}

int main() {
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

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int house, apartment;

        std::getline(input, city);
        std::getline(input, street);
        input >> house >> apartment;
        input.ignore();

        addresses[i] = new Address(city, street, house, apartment);
    }

    sort(addresses, N);

    output << N << "\n";
    for (int i = 0; i < N; ++i) {
        output << addresses[i]->get_output_address() << "\n";
        delete addresses[i];
    }

    delete[] addresses;

    std::cout << "The addresses are sorted and written to a file out.txt.\n";

    return 0;
}