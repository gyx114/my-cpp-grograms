#include <iostream>

using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point() : x(0), y(0) {}
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
};

class Rectangle
{
private:
    Point zuoxia;
    Point youshang;

public:
    Rectangle() : zuoxia(), youshang() {}
    Rectangle(Point a, Point b) : zuoxia(), youshang()
    {
        if (a.get_x() < b.get_x() && a.get_y() < b.get_y())
        {
            zuoxia = a;
            youshang = b;
        }
        else
        {
            cout << "相对位置错误！" << endl;
        }
    }

    double get_area()
    {
        double chang = youshang.get_x() - zuoxia.get_x();
        double kuan = youshang.get_y() - zuoxia.get_y();
        double area = chang * kuan;
        return area;
    }
};

int main()
{
    Point a(0, 0);
    Point b(3, 4);

    Point c(6, 8);
    Point d(2, 4);

    Rectangle rec1(a, b);
    Rectangle rec2(c, d);
    Rectangle rec3(d, c);
    Rectangle rec4;

    cout << rec1.get_area() << endl;
    cout << rec2.get_area() << endl;
    cout << rec3.get_area() << endl;
    cout << rec4.get_area() << endl;
}
