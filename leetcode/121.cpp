#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while (r <= n - 1)
        {
            if (prices[r] < prices[l])
            {
                l = r;
                r = r + 1;
            }
            else
            {
                max_profit = max(max_profit, prices[r] - prices[l]);
                r++;
            }
        }
        return max_profit;
    }
};
