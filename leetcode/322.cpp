#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dp = vector<int>(1e4 + 1, -2);

    int coinChange(vector<int> &coins, int amount)
    {

        if (amount == 0)
        {
            return dp[amount] = 0;
        }
        if (dp[amount] != -2)
        {
            return dp[amount];
        }
        if (count(coins.begin(), coins.end(), amount))
        {
            return dp[amount] = 1;
        }

        int mn = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int cn = coins[i];
            if (amount < cn)
            {
                continue;
            }
            else
            {
                int x = 1 + coinChange(coins, amount - cn);
                if (x != 0)
                {
                    mn = min(mn, x);
                }
            }
        }
        if (mn == INT_MAX)
        {
            mn = -1;
        }
        return dp[amount] = mn;
    }
};
