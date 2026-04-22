#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> ans(n + 1, 666);
        ans[0] = 1;
        ans[1] = 1;
        if (n == 1)
        {
            return 1;
        }
        for (int i = 2; i <= n; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2];
        }
        return ans[n];
    }
};
