#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int totalprofit = 0;
        int l = 0;
        int r = 1;
        while (r < n)
        {
            int pl = prices[l];
            int pr = prices[r];
            if (pl <= pr)
            {
                totalprofit += pr - pl;
            }
            l = r;
            r++;
        }
        return totalprofit;
    }
};
