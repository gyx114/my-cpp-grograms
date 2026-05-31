#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // dp + 三指针
        vector<int> dp(n);
        dp[0] = 1;
        int i2 = 0; // dp中前面的某个位置,用于*2得到新数
        int i3 = 0; // dp中前面的某个位置,用于*3得到新数
        int i5 = 0; // dp中前面的某个位置,用于*5得到新数
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(min(dp[i2] * 2, dp[i3] * 3), dp[i5] * 5);
            if (dp[i] == dp[i2] * 2)
            {
                i2++;
            }
            if (dp[i] == dp[i3] * 3)
            {
                i3++;
            }
            if (dp[i] == dp[i5] * 5)
            {
                i5++;
            }
        }
        return dp.back();
    }
};
