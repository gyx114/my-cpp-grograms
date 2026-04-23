#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
protected:
    double length, width;

public:
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {}
    double getArea() const override { return length * width; }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r = 0) : radius(r) {}
    double getArea() const override { return M_PI * radius * radius; }
};

class Square : public Rectangle
{
public:
    Square(double s = 0) : Rectangle(s, s) {}
    double getArea() const override { return length * length; }
};
