#include <iostream>

class Figure
{
protected:
    int numSides;
public:
    Figure(int sides) : numSides(sides) {}

    virtual void print_info() const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;
public:
    Triangle(double a, double b, double c, double A, double B, double C)
        : Figure(3), a(a), b(b), c(c), A(A), B(B), C(C) {}

    virtual void print_info() const override
    {
        std::cout << "Triangle:\n"
                  << "  Sides: a = " << a << ", b = " << b << ", c = " << c << "\n"
                  << "  Angles: A = " << A << ", B = " << B << ", C = " << C << "\n";
    }
};

class Quadrilateral : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;
public:
    Quadrilateral(double a, double b, double c, double d,
                  double A, double B, double C, double D)
        : Figure(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    virtual void print_info() const override
    {
        std::cout << "Quadrilateral:\n"
                  << "Sides: a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << "\n"
                  << "Angles: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << "\n";
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {}

    void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: Right Triangle\n";
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}

    void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: Isosceles Triangle\n";
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: Equilateral Triangle\n";
    }
};

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Rectangle\n";
    }
};

class Square : public Quadrilateral
{
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

    void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Square\n";
    }
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Parallelogram\n";
    }
};

class Rhombus : public Quadrilateral
{
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {}

    void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Rhombus\n";
    }
};

void print_info(const Figure* fig)
{
    fig->print_info();
    std::cout << std::endl;
}

int main() {

    Triangle tri(3, 4, 5, 50, 60, 70);
    RightTriangle rt(3, 4, 5, 50, 40);
    IsoscelesTriangle iso(5, 6, 40, 50);
    EquilateralTriangle eq(5);

    Quadrilateral quad(2, 3, 4, 5, 80, 90, 100, 90);
    Rectangle rect(4, 6);
    Square sq(5);
    Parallelogram par(4, 6, 70, 110);
    Rhombus romb(5, 70, 110);

    print_info(&tri);
    print_info(&rt);
    print_info(&iso);
    print_info(&eq);
    print_info(&quad);
    print_info(&rect);
    print_info(&sq);
    print_info(&par);
    print_info(&romb);

    return 0;
}
