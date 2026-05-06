#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 一个最通用的解决股票系列问题的动态规划状态定义是：
    // dp[i][k][0 or 1]
    // 含义：在第 i天，最多进行了 k次交易，当前持有(1)​ 或不持有(0)​ 股票时，能获得的最大利润。
    int maxProfit(vector<int> &prices)
    {
        int buy1 = INT_MIN; // 一次买入后现金
        int sell1 = 0;      // 买一次卖一次的现金
        int buy2 = INT_MIN; // 买卖之后再买一次的现金
        int sell2 = 0;      // 买卖两次后的现金
        // buy1​ 始终追踪着“到目前为止，以最低成本第一次买入”的机会。
        // sell1​ 在 buy1的基础上，追踪“第一次交易能获得的最大利润”。
        // buy2​ 在 sell1的基础上，寻找“用第一次利润进行第二次投资的最佳买入点”（即买入后剩余现金最多）。
        // sell2​ 在 buy2的基础上，寻找“第二次交易的最佳卖出点”。
        for (auto pi : prices)
        {
            buy1 = max(buy1, -pi);
            sell1 = max(sell1, pi + buy1);
            buy2 = max(buy2, sell1 - pi);
            sell2 = max(sell2, pi + buy2);
        }
        return sell2;
    }
};
