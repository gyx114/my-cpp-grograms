#include <iostream>
#include <string>
using namespace std;
class Base
{ // 有虚函数，因此是多态基类
public:
    virtual ~Base() {}
    int a = 0;
};

class Derived1 : public Base
{
public:
    int a = 10;
};

class Derived2 : public Derived1
{
public:
    int a = 20;
};

int main()
{

    Base *bp = new Derived2();
    Derived1 *pb = dynamic_cast<Derived1 *>(bp);
    Derived2 *pb2 = dynamic_cast<Derived2 *>(bp);
    cout << bp << " " << bp->a << endl;
    cout << pb << " " << pb->a << endl;
    cout << pb2 << " " << pb2->a << endl;

    return 0;
}
