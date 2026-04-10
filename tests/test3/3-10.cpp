#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    const int *ap1 = &a;
    int *const ap2 = &a;
    *ap1 = 10;
    ap1 = &b;
    *ap2 = 10;
    ap2 = &b;
    return 0;
}
