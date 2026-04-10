#include <iostream>
using namespace std;

void swap1(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

void swap2(int *a, int *b)
{
    int *t = a;
    a = b;
    b = t;
}

void swap3(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    int x = 5, y = 10;
    cout << "x = " << x << "    y = " << y << endl;
    swap1(x, y);
    cout << "x = " << x << "    y = " << y << endl;
    swap2(&x, &y);
    cout << "x = " << x << "    y = " << y << endl;
    swap3(x, y);
    cout << "x = " << x << "    y = " << y << endl;

    return 0;
}
