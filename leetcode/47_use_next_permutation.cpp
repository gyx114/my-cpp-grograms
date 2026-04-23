#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        auto i = nums;
        ans.push_back(i);
        do
        {
            next_permutation(nums.begin(), nums.end());
            ans.push_back(nums);

        } while (i != nums);
        ans.pop_back();
        return ans;
    }
};
