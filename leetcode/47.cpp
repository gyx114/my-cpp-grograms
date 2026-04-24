#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    // unordered_map<int, bool> mp;
    // idx:is_chosen

    // 直接用bool数组替换，效率更高

    void backtrack(vector<int> &nums, vector<bool> &is_chosen)
    {

        if (tmp.size() == nums.size())
        {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (is_chosen[i] == true)
            {
                continue;
            }
            // 与前一个数相同，且前面的数没被使用，表明这个数不能用，直接continue到下个数
            // 这保证了相同元素的相对位置和在nums中一样，nums中靠前的在tmp中就得靠前
            if (i != 0 && nums[i] == nums[i - 1] && !is_chosen[i - 1])
            {
                continue;
            }
            else
            {

                is_chosen[i] = true;
                tmp.push_back(nums[i]);

                backtrack(nums, is_chosen);

                is_chosen[i] = false;
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<bool> is_chosen(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, is_chosen);
        return ans;
    }
};
