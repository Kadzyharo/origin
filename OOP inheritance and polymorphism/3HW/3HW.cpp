#include <iostream>
#include <cmath>

class Figure
{
protected:
    int numSides;
public:
    Figure(int sides) : numSides(sides) {}

    virtual void print_info() const
    {
        std::cout << "Right figure: " << (is_valid() ? "Yes" : "No") << std::endl;
        std::cout << "Number of sides: " << numSides << std::endl;
    }

    virtual bool is_valid() const
    {
        return (numSides == 0);
    }

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
        std::cout << "Figure: Triangle" << std::endl;
        Figure::print_info();
        std::cout << "Sides: a = " << a
                  << ", b = " << b
                  << ", c = " << c << std::endl;
        std::cout << "Angles: A = " << A
                  << ", B = " << B
                  << ", C = " << C << std::endl;
    }

    virtual bool is_valid() const override
    {
        return std::fabs((A + B + C) - 180) < 1e-6;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90) {}

    virtual void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: RightTriangle\n";
    }

    virtual bool is_valid() const override
    {
        return Triangle::is_valid() && (fabs(C - 90) < 1e-6);
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}

    virtual void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: IsoscelesTriangle\n";
    }

    virtual bool is_valid() const override
    {
        return Triangle::is_valid() && (fabs(a - c) < 1e-6) && (fabs(A - C) < 1e-6);
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60, 60, 60) {}

    virtual void print_info() const override
    {
        Triangle::print_info();
        std::cout << "Triangle type: EquilateralTriangle\n";
    }

    virtual bool is_valid() const override
    {
        return Triangle::is_valid() && (fabs(a - b) < 1e-6)
                && (fabs(b - c) < 1e-6)
                && (fabs(A - 60) < 1e-6) && (fabs(B - 60) < 1e-6) && (fabs(C - 60) < 1e-6);
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
        : Figure(4), a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D){}

    virtual void print_info() const override
    {
        std::cout << "Figure: Quadrilateral" << std::endl;
        Figure::print_info();
        std::cout << "Sides: a = " << a
                  << ", b = " << b
                  << ", c = " << c
                  << ", d = " << d << std::endl;
        std::cout << "Angles: A = " << A
                  << ", B = " << B
                  << ", C = " << C
                  << ", D = " << D << std::endl;
    }

    virtual bool is_valid() const override
    {
        return std::fabs((A + B + C + D) - 360) < 1e-6;
    }
};

class Rectangle : public Quadrilateral
{
public:
    Rectangle(double a, double b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    virtual void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Rectangle\n";
    }

    virtual bool is_valid() const override
    {
        return Quadrilateral::is_valid() &&
               (fabs(a - c) < 1e-6) &&
               (fabs(b - d) < 1e-6) &&
               (fabs(A - 90) < 1e-6) && (fabs(B - 90) < 1e-6) &&
               (fabs(C - 90) < 1e-6) && (fabs(D - 90) < 1e-6);
    }
};

class Square : public Quadrilateral
{
public:
    Square(double side)
        : Quadrilateral(side, side, side, side, 90, 90, 90, 90) {}

    virtual void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Square\n";
    }

    virtual bool is_valid() const override
    {
        return Quadrilateral::is_valid() &&
               (fabs(a - b) < 1e-6) && (fabs(b - c) < 1e-6) && (fabs(c - d) < 1e-6) &&
               (fabs(A - 90) < 1e-6) && (fabs(B - 90) < 1e-6) &&
               (fabs(C - 90) < 1e-6) && (fabs(D - 90) < 1e-6);
    }
};

class Parallelogram : public Quadrilateral
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    virtual void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Parallelogram\n";
    }

    virtual bool is_valid() const override
    {
        return Quadrilateral::is_valid() &&
               (fabs(a - c) < 1e-6) &&
               (fabs(b - d) < 1e-6) &&
               (fabs(A - C) < 1e-6) &&
               (fabs(B - D) < 1e-6);
    }
};

class Rhombus : public Quadrilateral
{
public:
    Rhombus(double side, double A, double B)
        : Quadrilateral(side, side, side, side, A, B, A, B) {}

    virtual void print_info() const override
    {
        Quadrilateral::print_info();
        std::cout << "Quadrilateral type: Rhombus\n";
    }

    virtual bool is_valid() const override
    {
        return Quadrilateral::is_valid() &&
               (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6 && fabs(c - d) < 1e-6) &&
               (fabs(A - C) < 1e-6) && (fabs(B - D) < 1e-6);
    }
};

void print_info(const Figure* fig)
{
    fig->print_info();
    std::cout << "-------------------------------------" << std::endl;
}

int main() {
    Figure *fig = new Figure(0);

    Figure *tri = new Triangle(10, 20, 30, 50, 60, 70);
    Figure *rightTri = new RightTriangle(10, 20, 30, 50, 60);
    Figure *isoTri = new IsoscelesTriangle(10, 20, 40, 100);
    Figure *eqTri  = new EquilateralTriangle(5);

    Figure *quad = new Quadrilateral(2, 3, 4, 5, 80, 90, 100, 90);
    Figure *rect = new Rectangle(4, 6);
    Figure *sq   = new Square(5);
    Figure *par  = new Parallelogram(4, 6, 70, 110);
    Figure *romb = new Rhombus(5, 70, 110);

    print_info(fig);
    print_info(tri);
    print_info(rightTri);
    print_info(isoTri);
    print_info(eqTri);
    print_info(quad);
    print_info(rect);
    print_info(sq);
    print_info(par);
    print_info(romb);

    delete fig;
    delete tri;
    delete rightTri;
    delete isoTri;
    delete eqTri;
    delete quad;
    delete rect;
    delete sq;
    delete par;
    delete romb;

    return 0;
}
