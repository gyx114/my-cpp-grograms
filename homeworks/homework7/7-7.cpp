#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base 构造函数被调用" << endl;
    }
    ~Base()
    {
        cout << "Base 析构函数被调用" << endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived 构造函数被调用" << endl;
    }
    ~Derived()
    {
        cout << "Derived 析构函数被调用" << endl;
    }
};

int main()
{
    Derived d;
    return 0;
}
