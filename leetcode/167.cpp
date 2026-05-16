#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> ans;
        vector<int> &nums = numbers;
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (nums.front() + nums[r] > target)
        {
            r--;
        }
        while (l < r)
        {
            int nl = nums[l];
            int nr = nums[r];
            if (nl + nr == target)
            {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }
            else if (nl + nr < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
