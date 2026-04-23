#include <iostream>
using namespace std;

class Base0
{
    int var0;
};
class Base1 : virtual public Base0
{
    int var1;
};
class Base2 : virtual public Base0
{
    int var2;
};
class Derived : public Base1, public Base2
{
    int var3;
};

int main()
{
    Derived *pd = new Derived();
    Base2 *pb2 = pd;
    void *pv = pd;
    Base2 *pb22 = static_cast<Base2 *>(pv);
    cout << pd << endl;
    cout << pv << endl;
    cout << pb2 << endl;
    cout << pb22 << endl;
}
