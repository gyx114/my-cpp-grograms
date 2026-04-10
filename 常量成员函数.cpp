#include <iostream>

using namespace std;

class A
{

public:
    void f()
    {
        cout << "你不是const" << endl;
    }
    void f() const
    {
        cout << "你是const" << endl;
    }
};

int main()
{
    A a;
    const A b;
    a.f();
    b.f();
}
