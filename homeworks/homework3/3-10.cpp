#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int x, y;
    cout << "请输入两个正整数：" << endl;
    cin >> x >> y;

    int g = gcd(x, y);
    int l = lcm(x, y);

    cout << "最大公约数：" << g << endl;
    cout << "最小公倍数：" << l << endl;

    return 0;
}
