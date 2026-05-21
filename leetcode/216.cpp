#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;

    void backtrack(int tar, int beg, int k)
    {
        if (9 - beg + 1 < k)
        {
            return;
        }
        else if (k == 0)
        {
            if (tar == 0)
            {
                ans.push_back(tmp);
            }
            return;
        }
        else
        {
            for (int i = beg; i <= 9; i++)
            {
                tmp.push_back(i);
                backtrack(tar - i, i + 1, k - 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(n, 1, k);
        return ans;
    }
};
