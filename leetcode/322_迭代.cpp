#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        sort(coins.begin(), coins.end());
        long long idx = 0;
        dp[0] = 0;
        while (idx <= amount)
        {
            if (dp[idx] == INT_MAX)
            {
                idx++;
                continue;
            }
            for (auto cn : coins)
            {
                if (idx + cn <= amount)
                {
                    dp[idx + cn] = min(dp[idx + cn], dp[idx] + 1);
                }
                else
                {
                    break;
                }
            }
            idx++;
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
