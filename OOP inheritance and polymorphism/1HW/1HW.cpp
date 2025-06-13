#include <iostream>

class Figure
{
public:
    virtual int getSidesCount() const
    {
        return 0;
    }

    virtual ~Figure() = default;
};

class Triangle : public Figure
{
public:
    int getSidesCount() const override
    {
        return 3;
    }
};

class Quadrilateral : public Figure
{
public:
    int getSidesCount() const override
    {
        return 4;
    }
};

int main()
{
    Figure* unknown = new Figure();
    Figure* triangle = new Triangle();
    Figure* quadrilateral = new Quadrilateral();

    std::cout << "Unknown figure: " << unknown->getSidesCount() << " side(s)" << std::endl;
    std::cout << "Triangle: " << triangle->getSidesCount() << " sides" << std::endl;
    std::cout << "Quadrilateral: " << quadrilateral->getSidesCount() << " sides" << std::endl;

    delete unknown;
    delete triangle;
    delete quadrilateral;

    return 0;
}
