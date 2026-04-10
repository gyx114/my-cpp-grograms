#include <iostream>

using namespace std;

class Point
{

private:
    int x;
    int y;

public:
    Point()
    {
        x = 0;
        y = 0;
    } // 默认
    Point(int x, int y);
    ~Point();

    void print();
    void move(int dx, int dy);
};

void Point::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Point::print()
{
    cout << "x:" << x << endl;
    cout << "y:" << y << endl;
}

Point::Point(int x, int y)
{
    Point::x = x;
    Point::y = y; // 有重名变量，需要带解析符 Point::x
    cout << "x is " << x << endl;
    cout << "y is " << y << endl;
}

Point::~Point()
{
    cout << "析构" << endl;
}

int main()
{
    Point p1;
    p1.print();
    p1.move(114, 514);
    p1.print();

    Point p2(3, 4);

    cout << "在p3作用域之外" << endl;
    {
        Point p3 = p1; // 拷贝构造，把p1全部复制到p3
        cout << &p3 << endl
             << &p1 << endl;

        p2 = p1; // 拷贝赋值，把p1全部赋值到p2

        p3.print();
    }
    cout << "在p3作用域之外" << endl;

    p2.print();

    return 0;
}
