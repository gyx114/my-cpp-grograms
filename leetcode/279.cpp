#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            int sqrti = static_cast<int>(sqrt(i));
            if (sqrti * sqrti == i)
            {
                dp[i] = 1;
            }
            else
            {
                int minn = INT_MAX;
                for (int j = 1; j <= sqrti; j++)
                {
                    int cur = dp[j * j] + dp[i - j * j];
                    minn = min(minn, cur);
                }
                dp[i] = minn;
            }
        }
        return dp[n];
    }
};
