#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    unordered_map<int, bool> mp;

    void backtrack(vector<int> &nums)
    {
        if (tmp.size() == nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[i] == true)
            {
                continue;
            }
            else
            {
                tmp.push_back(nums[i]);
                mp[i] = true;
                backtrack(nums);
                tmp.pop_back();
                mp[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        backtrack(nums);
        return ans;
    }
};
