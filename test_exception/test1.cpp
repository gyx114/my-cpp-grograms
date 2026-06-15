#include <iostream>
#include <exception>
#include <memory>
using namespace std;

void f()
{
    throw 3;
}

int main()
{
    try
    {
        f();
    }
    catch (char x)
    {
        cerr << "char" << endl;
    }
    catch (long long x)
    {
        cerr << "ll" << endl;
    }
    catch (int x)
    {
        cerr << "int" << endl;
    }
    int *p = new int(3);
    auto_ptr<int> ptr1(p);
    cout << *ptr1;
}
