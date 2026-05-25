#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool is_pali(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = s[i] == s[j] && is_pali(s, i + 1, j - 1, dp);
    }

    string shortestPalindrome(string &s)
    {
        if (s.empty())
        {
            return s;
        }
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int l = 1;
        for (int j = n - 1; j >= 0; j--)
        {
            if (is_pali(s, 0, j, dp))
            {
                l = j + 1;
                break;
            }
        }
        string remain = s.substr(l);
        reverse(remain.begin(), remain.end());
        remain += s;
        return remain;
    }
};
