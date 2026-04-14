#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    set<vector<long long>> threeSum(vector<int> &nums, long long tar, long long l)
    {
        set<vector<long long>> ans_set;
        for (long long i = l; i <= nums.size() - 3; i++)
        {
            long long lft = i + 1;
            long long rht = nums.size() - 1;
            while (lft < rht)
            {
                long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[lft]) + static_cast<long long>(nums[rht]);
                if (sum > tar)
                {
                    rht--;
                }
                else if (sum < tar)
                {
                    lft++;
                }
                else
                {
                    vector<long long> tmp = {nums[i], nums[lft], nums[rht]};
                    ans_set.insert(tmp);
                    lft++;
                    rht--;
                }
            }
        }
        return ans_set;
    }

    vector<vector<int>> fourSum(vector<int> &nums, long long target)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if (nums.size() < 4)
        {
            return ans;
        }
        set<vector<long long>> ans_set;
        for (long long i = 0; i <= nums.size() - 4; i++)
        {
            set<vector<long long>> tmp = threeSum(nums, target - nums[i], i + 1);
            if (tmp.size() != 0)
            {
                for (auto v : tmp)
                {
                    v.push_back(nums[i]);
                    ans_set.insert(v);
                }
            }
        }

        for (auto v : ans_set)
        {

            vector<int> t;
            for (auto i : v)
            {
                t.push_back(static_cast<int>(i));
            }
            ans.push_back(t);
        }
        return ans;
    }
};
