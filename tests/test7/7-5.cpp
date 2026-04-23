#include <iostream>
using namespace std;

class Point
{
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }

    Point &operator=(const Point &p)
    {
        if (this != &p)
        { // 防止自赋值
            x = p.x;
            y = p.y;
        }
        return *this;
    }

    bool operator==(const Point &p) const
    {
        return (x == p.x) && (y == p.y);
    }

    void display() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
