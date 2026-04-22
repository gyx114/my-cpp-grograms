#include <bits/stdc++.h>
using namespace std;

// 回溯

class Solution
{
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    void call_back(vector<int> &nums, int target, int begin)
    {
        if (target <= 0)
        {
            if (target == 0)
            {
                ans.push_back(tmp);
            }

            return;
        }
        else
        {
            for (int i = begin; i < nums.size(); i++)
            {
                tmp.push_back(nums[i]);
                call_back(nums, target - nums[i], i);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        call_back(candidates, target, 0);
        return ans;
    }
};
