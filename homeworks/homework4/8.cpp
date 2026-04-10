#include <iostream>
using namespace std;

class Circle
{
private:
    double radius;

public:
    Circle() : radius(0) {}
    Circle(double r) : radius(0)
    {
        if (r <= 0)
        {
            cout << "error!" << endl;
        }
        else
        {
            radius = r;
        }
    }

    double getArea()
    {
        double area;
        area = 3.14 * radius * radius;
        return area;
    }
};

int main()
{
    Circle circ1;
    Circle circ2(6);
    Circle circ3(-4);

    cout << circ1.getArea() << endl;
    cout << circ2.getArea() << endl;
    cout << circ3.getArea() << endl;
}
