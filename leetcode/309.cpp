#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> buy(n, -prices[0]);
        vector<int> sell(n);
        for (int i = 1; i < n; i++)
        {
            buy[i] = max(buy[i - 1], (i - 2 >= 0 ? sell[i - 2] : 0) - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        // 可以滚动数组优化
        return sell[n - 1];
    }
};
