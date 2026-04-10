#include <iostream>
using namespace std;

short int f(unsigned short int a, unsigned short int b)
{
    if (b == 0)
        return -1;
    return static_cast<short int>(a / b);
}

int main()
{
    cout << "输入两个short int" << endl;
    short int a, b;
    cin >> a >> b;
    cout << f(a, b) << endl;
}
