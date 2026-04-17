#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

int main()
{
    cout << reverse(120) << endl;
}
