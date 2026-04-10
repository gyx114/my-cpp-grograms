#include <iostream>

using namespace std;

class A
{
private:
    int i;

public:
    A() : i(0)
    {
        cout << "A::A()" << endl;
    }

    A(int ii) : i(ii)
    {
        cout << "A:A(int)" << endl;
    }

    void f(int x)
    {
        cout << "A " << x << endl;
    }
    void f()
    {
        cout << "A null" << endl;
    }
    void hello()
    {
        cout << "hello" << endl;
    }
};

class B : public A
{

public:
    B(int i) : A(i)
    {
        cout << "B:B(int)" << endl;
    }
    B() : A(0)
    {
        cout << "B:B()" << endl;
    }

    void f()
    {
        cout << "B::f()" << endl;
        A::f();
    }
};

int main()
{
    B b(6);
    b.f();
    b.A::f(3);
    b.A::hello();
}
