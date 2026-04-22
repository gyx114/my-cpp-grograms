#include <bits/stdc++.h>
using namespace std;
class Solution
{

    vector<vector<int>> ans;
    vector<int> tmp;

    void backtrack(vector<int> &nums, int target, int begin)
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
                // i!=begin保证了不同层级中可以选相同数(即i=begin时可以加入),保证了不漏[1,1,2]
                // 但是在同一层级中不允许选相同数(i>begin时不能加入),保证不重[1,3],[1,3]
                if (i != begin && nums[i] == nums[i - 1])
                {
                    continue;
                }
                if (nums[i] > target)
                    return;
                tmp.push_back(nums[i]);
                backtrack(nums, target - nums[i], i + 1);
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);

        return ans;
    }
};
