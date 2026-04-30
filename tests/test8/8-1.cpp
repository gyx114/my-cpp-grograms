#include <iostream>
using namespace std;

class Base
{
public:
    ~Base();
};
Base::~Base()
{
    cout << "Base destructor" << endl;
}

class Derived : public Base
{
public:
    Derived();
    ~Derived();

private:
    int *p;
};

Derived::Derived()
{
    p = new int(0);
}

Derived::~Derived()
{
    cout << "Derived destructor" << endl;
    delete p;
}

void fun(Base *b)
{
    delete b; // 只执行基类析构
}

int main()
{
    Derived d1;
    fun(&d1);
}
