#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<int> &nums = prices;
        int n = nums.size();
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, INT_MIN);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                if (j == 0)
                {
                    buy[j] = 0;
                    sell[j] = 0;
                }
                else
                {
                    buy[j] = max(buy[j], sell[j - 1] - nums[i]); // 用之前的还是买入
                    sell[j] = max(sell[j], buy[j] + nums[i]);    // 用之前的还是卖出
                }
            }
        }
        return sell[k];
    }
};
