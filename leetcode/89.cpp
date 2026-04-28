#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judge(int x, int y)
    {
        int diff = x ^ y;
        return diff > 0 && (diff & (diff - 1)) == 0;
    }
    vector<int> ans = {0};
    int is_ok = 0;
    void backtrack(int n, vector<bool> &used)
    {
        if (is_ok)
        {
            return;
        }
        if (ans.size() == 1 << n)
        {

            if (judge(ans.front(), ans.back()))
            {
                is_ok = 1;
            }
            return;
        }
        else
        {
            for (int i = 1; i < (1 << n); i++)
            {
                if (!used[i])
                {
                    if (judge(i, ans.back()))
                    {
                        ans.push_back(i);
                        used[i] = true;

                        backtrack(n, used);
                        if (is_ok)
                        {
                            return;
                        }
                        used[i] = false;
                        ans.pop_back();
                    }
                }
            }
        }
    }
    vector<int> grayCode(int n)
    {
        vector<bool> used((1 << n), false);
        used[0] = true;
        backtrack(n, used);
        return ans;
    }
};
