#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    a = (a = (a = 2 * a + 1) + 2) * 3 + a;
    cout << a << endl;
}
