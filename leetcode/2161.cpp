#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> ans(n, pivot);

        int l = 0;
        int r = n - 1;
        for (auto &x : nums)
        {
            if (x < pivot)
            {
                ans[l++] = x;
            }
            else if (x > pivot)
            {
                ans[r--] = x;
            }
        }
        reverse(ans.begin() + r + 1, ans.end());
        return ans;

        // vector<int> v1;
        // vector<int> v2;
        // for (auto x : nums)
        // {
        //     if (x < pivot)
        //     {
        //         v1.push_back(x);
        //     }
        //     else if (x > pivot)
        //     {
        //         v2.push_back(x);
        //     }
        // }
        // int n1 = v1.size();
        // int n2 = v2.size();
        // for (int i = 0; i < n1; i++)
        // {
        //     ans[i] = v1[i];
        // }
        // for (int i = 0; i < n2; i++)
        // {
        //     ans[n - 1 - i] = v2[n2 - 1 - i];
        // }
        // return ans;
    }
};
