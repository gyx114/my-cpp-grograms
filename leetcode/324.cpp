#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < (n + 1) / 2; i += 2)
        {
            swap(nums[i], nums[(n + 1) / 2 + i]);
        }
    }
};
