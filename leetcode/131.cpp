#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    vector<string> tmp;
    void backtrack(string &s, vector<vector<bool>> &dp, int beg)
    {
        int n = s.length();
        if (beg >= n)
        {
            ans.push_back(tmp);
        }
        for (int i = beg; i < n; i++)
        {
            if (dp[beg][i])
            {
                tmp.push_back(s.substr(beg, i - beg + 1));
                backtrack(s, dp, i + 1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string &s)
    {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] != s[j] || !dp[i + 1][j - 1])
                {
                    dp[i][j] = false;
                }
            }
        }
        backtrack(s, dp, 0);
        return ans;
    }
};
