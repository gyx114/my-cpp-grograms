#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double myPow(double x, int nn)
    {
        // 开挂
        // return pow(x, n);
        long long n = nn;
        if (x == 0 || x == 1)
        {
            return x;
        }

        bool is_nega = false;
        if (n < 0)
        {
            is_nega = true;
            n = -n;
        }
        double ans = 1;
        double tmp = x;
        while (n != 0)
        {
            if (n & 1)
            {
                ans *= tmp;
            }
            n >>= 1;
            tmp = tmp * tmp;
        }
        return is_nega ? (1.0 / ans) : ans;
    }
};
