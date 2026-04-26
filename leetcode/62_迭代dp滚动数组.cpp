#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[0] = 1;
                }
                else
                {
                    int up = i > 0 ? dp[j] : 0;
                    int lft = j > 0 ? dp[j - 1] : 0;
                    dp[j] = up + lft;
                }
            }
        }
        return dp[n - 1];
    }
};
