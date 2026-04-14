#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void find2(vector<int> &ansi, set<vector<int>> &ans_set, vector<int> &nums, int lft, int rht, int tar)
    {
        while (lft < rht)
        {
            int val_lft = nums[lft];
            int val_rht = nums[rht];
            if (val_lft + val_rht > tar)
            {
                rht--;
            }
            else if (val_lft + val_rht < tar)
            {
                lft++;
            }
            else
            {
                ansi = {-tar, val_lft, val_rht};

                ans_set.insert(ansi);
                lft++;
                rht--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<int> ansi;
        vector<vector<int>> ans;
        set<vector<int>> ans_set;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n < 3)
        {
            return ans;
        }
        else
        {
            for (int i = 0; i <= n - 3; i++)
            {
                find2(ansi, ans_set, nums, i + 1, n - 1, -nums[i]);
            }
        }
        ans.insert(ans.begin(), ans_set.begin(), ans_set.end());
        return ans;
    }
};
