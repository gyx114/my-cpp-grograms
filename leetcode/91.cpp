#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getnum(string &s, int r, vector<int> &dp)
    {
        if (r < 0)
        {
            return 1;
        }
        if (dp[r] != -1)
        {
            return dp[r];
        }
        if (r == 0)
        {
            if (s[r] == '0')
            {
                return dp[0] = 0;
            }
            else
            {
                return dp[0] = 1;
            }
        }

        else
        {
            int n1 = s[r] == '0' ? 0 : getnum(s, r - 1, dp);
            int n2 = 0;

            if (s[r - 1] == '0')
            {
                n2 = 0;
            }
            else if ((s[r - 1] == '2' && s[r] <= '6') || s[r - 1] == '1' && s[r] <= '9')
            // 这里可以先转成数字  10*(s[r-1]-'0')+s[r]-'0'  再进行判断
            {
                n2 = getnum(s, r - 2, dp);
            }
            else
            {
                n2 = 0;
            }
            return dp[r] = n1 + n2;
        }
    }

    int numDecodings(string s)
    {
        vector<int> dp(s.length(), -1);
        return getnum(s, s.length() - 1, dp);
    }
};
