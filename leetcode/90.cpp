#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void backtrack(vector<int> &nums, int begin, vector<bool> &used)
    {
        if (begin >= used.size())
        {
            ans.push_back(tmp);
            return;
        }

        if (begin > 0 && nums[begin - 1] == nums[begin] && !used[begin - 1])
        {
            // dont choose
            backtrack(nums, begin + 1, used);
        }
        else
        {
            // choose
            tmp.push_back(nums[begin]);
            used[begin] = true;

            backtrack(nums, begin + 1, used);

            used[begin] = false;
            tmp.pop_back();

            // dont choose
            backtrack(nums, begin + 1, used);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> used(n, false);
        backtrack(nums, 0, used);
        return ans;
    }
};
