#include <iostream>

using namespace std;
class Point
{       // 类的定义
public: // 外部接口
    Point() : Point(0, 0) {};
    Point(int x, int y);
    ~Point();
    void move(int newX, int newY);
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount(); // 静态函数成员
private:                     // 私有数据成员
    int x, y, id;
    static int count;
};

int Point::count = 0;

Point::Point(int x, int y) : x(x), y(y)
{
    id = count++;
    cout << "Constructor called." << id << endl;
}
Point::~Point()
{
    cout << "Destructor called." << id << endl;
}
void Point::move(int newX, int newY)
{
    cout << "Moving the point to (" << newX << ", " << newY << ")" << endl;
    x = newX;
    y = newY;
}

int main()
{
    cout << "Entering main..." << endl;
    Point a1;
    Point *a2 = new Point;
    {
        Point a1;
        Point *a2 = new Point;
    }
    delete a2;

    return 0;
}
