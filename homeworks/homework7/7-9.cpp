#include <iostream>
using namespace std;

class Base
{
public:
    void fn1() { cout << "Base::fn1() 被调用" << endl; }
    void fn2() { cout << "Base::fn2() 被调用" << endl; }
};

class Derived : private Base
{
public:
    void callFn1() { fn1(); }
    void callFn2() { fn2(); }
};

int main()
{
    Derived d;
    d.callFn1();
    d.callFn2();
    return 0;
}
