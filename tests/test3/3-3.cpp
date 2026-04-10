#include <iostream>
using namespace std;

class A
{
public:
    int n1 : 2;
    int n2 : 1;
    int n3 : 2;
};

int main()
{

    A a;
    cout << sizeof(a) << endl;
}
