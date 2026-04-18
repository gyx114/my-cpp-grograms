#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int n)
    {
        int ans = 0;
        while (n != 0)
        {
            ans = ans * 10 + n % 10;
            n /= 10;
        }
        return ans;
    }

    int mirrorDistance(int n)
    {
        return abs(n - reverse(n));
    }
};
