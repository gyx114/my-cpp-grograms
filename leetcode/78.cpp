#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int len = pow(2, n);
        for (int i = 0; i < len; i++)
        {
            int t = i;
            vector<int> tmp;
            for (auto q : nums)
            {
                if (t & 1)
                {
                    tmp.push_back(q);
                }
                t >>= 1;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
