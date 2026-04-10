#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num;
    cout << "请输入一个整数：";
    cin >> num;

    if (is_prime(num))
    {
        cout << num << " 是质数。" << endl;
    }
    else
    {
        cout << num << " 不是质数。" << endl;
    }

    return 0;
}
