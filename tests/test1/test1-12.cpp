#include <iostream>
using namespace std;

void print_address1(int a, int b)
{
    cout << &a << "\t" << &b << endl;
}

void print_address2(int &a, int &b)
{
    cout << &a << "\t" << &b << endl;
}

int main()
{
    int a = 0;
    int b = 0;
    cout << &a << "\t" << &b << endl;
    print_address1(a, b);
    print_address2(a, b);
}
