#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nums;
    // 符号也存入，有以下映射：
    //-1:+
    //-2:-
    //-3:*

    vector<int> &dfs(vector<vector<vector<int>>> &dp, int l, int r)
    {
        vector<int> tmp;

        if (r >= dp.size() || l < 0 || l > r)
        {
            return dp[1][0];
        }

        if (!dp[l][r].empty())
        {
            return dp[l][r];
        }

        if (l == r)
        {
            tmp.push_back(nums[l]);
            return dp[l][r] = move(tmp);
        }

        for (int i = l + 1; i <= r; i += 2)
        {
            auto &lft = dfs(dp, l, i - 1);
            auto &rht = dfs(dp, i + 1, r);
            for (auto x : lft)
            {
                for (auto y : rht)
                {
                    switch (nums[i])
                    {
                    case -1:
                        tmp.push_back(x + y);
                        break;
                    case -2:
                        tmp.push_back(x - y);
                        break;

                    case -3:
                        tmp.push_back(x * y);
                        break;
                    }
                }
            }
        }
        return dp[l][r] = move(tmp);
    }

    vector<int> diffWaysToCompute(string expression)
    {

        for (int i = 0; i < expression.size(); i++)
        {
            int val = 0;
            if (isdigit(expression[i]))
            {
                val = expression[i] - '0';
                if (i + 1 < expression.size() && isdigit(expression[i + 1]))
                {
                    val = val * 10 + expression[i + 1] - '0';
                    i++;
                }
            }
            else
            {
                switch (expression[i])
                {
                case '+':
                    val = -1;
                    break;
                case '-':
                    val = -2;
                    break;

                case '*':
                    val = -3;
                    break;
                }
            }
            nums.push_back(val);
        }
        int n = nums.size();
        vector<vector<vector<int>>> dp(vector<vector<vector<int>>>(n, vector<vector<int>>(n)));
        // dp记忆化，dp[i][j]表示nums中下标[i-j]的部分产生的所有结果
        return dfs(dp, 0, n - 1);
    }
};
