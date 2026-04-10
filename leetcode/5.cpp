
/*通过dp实现寻找最长回文子串*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        bool dp[len][len];
        int start_and_len[2] = {0, 1};

        int max_len = 1;

        for (int cur_len = 1; cur_len <= len; cur_len++)
        {

            for (int i = 0; i + cur_len - 1 < len; i++)
            {
                int j = i + cur_len - 1;
                if (cur_len == 1)
                {
                    dp[i][j] = true;
                }
                else if (cur_len == 2)
                {
                    dp[i][j] = s[i] == s[j];
                    if (dp[i][j] && cur_len > max_len)
                    {
                        max_len = cur_len;
                        start_and_len[0] = i;
                        start_and_len[1] = cur_len;
                    }
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    if (dp[i][j] && cur_len > max_len)
                    {
                        max_len = cur_len;
                        start_and_len[0] = i;
                        start_and_len[1] = cur_len;
                    }
                }
            }
        }

        return s.substr(start_and_len[0], start_and_len[1]);
    }
};
