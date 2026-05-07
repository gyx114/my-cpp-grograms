#include <iostream>
using namespace std;
class Shape
{
public:
    virtual double getArea() const = 0;
    virtual double getPerim() const = 0;
    Shape() {}
    virtual ~Shape() {}
};

class Rectangle : public Shape
{
private:
    double length;
    double height;

public:
    Rectangle(double len = 0, double hei = 0) : length(len), height(hei) {}
    ~Rectangle() override {};

    double getArea() const override
    {
        return length * height;
    }
    double getPerim() const override
    {
        return 2 * (length + height);
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r = 0) : radius(r) {}
    ~Circle() override {};

    double getArea() const override
    {
        return 3.14 * radius * radius;
    }
    double getPerim() const override
    {
        return 2 * 3.14 * radius;
    }
};

int main()
{
    Circle c1(3);
    Rectangle rec1(3, 4);
    cout << c1.getArea() << endl;
    cout << c1.getPerim() << endl;
    cout << rec1.getArea() << endl;
    cout << rec1.getPerim() << endl;
}
