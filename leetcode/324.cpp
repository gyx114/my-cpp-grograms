#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n);
        sort(nums.begin(), nums.end());
        int x = (n + 1) / 2;
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--)
        {
            arr[i] = nums[j];
            if (i + 1 < n)
            {
                arr[i + 1] = nums[k];
            }
        }
        nums.swap(arr);
    }
};
