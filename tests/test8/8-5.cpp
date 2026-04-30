#include <iostream>
using namespace std;
class A
{
private:
    const int i = 10;

public:
    void show()
    {
        cout << i << endl;
    }
};

int main()
{
    A a;
    // 填入代码
    int *p = reinterpret_cast<int *>(&a);
    *p = 20;

    a.show();
}
