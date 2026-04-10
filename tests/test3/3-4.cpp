#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 1;
    cout << "a = " << a << " b = " << b << endl;
    {
        int b = 3;
        cout << "a = " << a << " b = " << b << endl;
    }
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}
