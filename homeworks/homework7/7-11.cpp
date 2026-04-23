#include <iostream>
using namespace std;

class BaseClass
{
public:
    void fn1()
    {
        cout << "BaseClass::fn1() called" << endl;
    }
    void fn2()
    {
        cout << "BaseClass::fn2() called" << endl;
    }
};

class DerivedClass : public BaseClass
{
public:
    void fn1()
    {
        cout << "DerivedClass::fn1() called" << endl;
    }
    void fn2()
    {
        cout << "DerivedClass::fn2() called" << endl;
    }
};

int main()
{
    DerivedClass d;

    cout << "=== 使用 DerivedClass 对象直接调用 ===" << endl;
    d.fn1();
    d.fn2();

    cout << "\n=== 使用 BaseClass* 指针调用 ===" << endl;
    BaseClass *basePtr = &d;
    basePtr->fn1();
    basePtr->fn2();

    cout << "\n=== 使用 DerivedClass* 指针调用 ===" << endl;
    DerivedClass *derivedPtr = &d;
    derivedPtr->fn1();
    derivedPtr->fn2();

    return 0;
}
