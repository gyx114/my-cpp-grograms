#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define ull unsigned long long
    int numDistinct(string s, string t)
    {
        int l1 = s.length();
        int l2 = t.length();
        if (l1 < l2)
        {
            return 0;
        }
        vector<vector<ull>> dp(l1, vector<ull>(l2));
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                if (i < j)
                {
                    break;
                }
                ull up = i > 0 ? dp[i - 1][j] : 0;
                ull uplft = i > 0 && j > 0 ? dp[i - 1][j - 1] : 1;
                if (s[i] == t[j])
                {
                    dp[i][j] = up + uplft;
                }
                else
                {
                    dp[i][j] = up;
                }
            }
        }
        return dp[l1 - 1][l2 - 1];
    }
};
