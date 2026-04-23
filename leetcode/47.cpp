#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    unordered_map<int, bool> mp;
    // idx:is_chosen

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
            // 与前一个数相同，且前面的数没被使用，表明这个数不能用，直接continue到下个位置的数
            if (i != 0 && nums[i] == nums[i - 1] && !mp[i - 1])
            {
                continue;
            }
            else
            {

                mp[i] = true;
                tmp.push_back(nums[i]);

                backtrack(nums);

                mp[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtrack(nums);
        return ans;
    }
};
