#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtrack(int l, int r, int n, int k)
    {
        if (k <= 0)
        {
            ans.push_back(tmp);
            return;
        }
        if (l > n)
        {
            return;
        }
        if (k > r - l + 1)
        {
            return;
        }
        else
        {

            // 选当前
            tmp.push_back(l);
            backtrack(l + 1, r, n, k - 1);
            tmp.pop_back();

            // 不选当前
            backtrack(l + 1, r, n, k);
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtrack(1, n, n, k);
        return ans;
    }
};
