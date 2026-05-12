#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int premax = nums[0]; // 下标为i向左延伸出最大乘积
        int premin = nums[0]; // 下标为i向左延伸出最小乘积
        int max_plus = nums[0];
        for (int i = 1; i < n; i++)
        {
            int a = premax * nums[i];
            int b = premin * nums[i];
            int c = nums[i];
            premax = max(a, max(b, c));
            premin = min(a, min(b, c));
            max_plus = max(max_plus, premax);
        }
        return max_plus;
    }
};
