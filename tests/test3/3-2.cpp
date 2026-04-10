#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

union U
{
    A a;
    double d;
};

int main()
{
    U u;
    A a;
    a.a = 1;
    u.a = a;
    u.d = 1.0;
    cout << u.a.a << endl;
    cout << u.d << endl;
    return 0;
}
