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
        vector<ull> dp(l2);
        for (int i = 0; i < l1; i++)
        {
            // 注意，这里是倒序遍历，因为如果正序遍历，左上角的信息会丢失(dp[j-1]已经更新，表示左边而不是左上角)
            for (int j = l2 - 1; j >= 0; j--)
            {
                if (i < j)
                {
                    continue;
                }
                ull up = i > 0 ? dp[j] : 0;
                ull uplft = i > 0 && j > 0 ? dp[j - 1] : 1;
                if (s[i] == t[j])
                {
                    dp[j] = up + uplft;
                }
                else
                {
                    dp[j] = up;
                }
            }

            // 当然，也可以正序遍历，只不过需要维护一个变量，存储修改前的值，也就是左上角的值
            // ull tmp = 0;
            // for (int j = 0; j < l2; j++)
            // {
            //     if (i < j)
            //     {
            //         continue;
            //     }
            //     ull up = i > 0 ? dp[j] : 0;
            //     ull uplft = i > 0 && j > 0 ? tmp : 1;
            //     if (s[i] == t[j])
            //     {
            //         tmp = dp[j];
            //         dp[j] = up + uplft;
            //     }
            //     else
            //     {
            //         tmp = dp[j];
            //         dp[j] = up;
            //     }
            // }
        }
        return dp[l2 - 1];
    }
};
