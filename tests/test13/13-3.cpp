#include <iostream>
using namespace std;
int divide(int x, int y)
{
    if (y == 0)
        throw x;
    return x / y;
}
class A
{
    int id;

public:
    A(int i) : id(i)
    {
        cout << "object " << id << " is constructed" << endl;
    }
    ~A()
    {
        cout << "object " << id << " is deconstructed" << endl;
    }
};
int main()
{
    try
    {
        A a0(0);
        cout << "5 / 2 = " << divide(5, 2) << endl;
        A a1(1);
        cout << "8 / 0 = " << divide(8, 0) << endl;
        A a2(2);
        cout << "7 / 1 = " << divide(7, 1) << endl;
        A a3(3);
    }
    catch (int e)
    {
        cout << e << " is divided by zero!" << endl;
    }
    cout << "That is ok." << endl;
    return 0;
}
