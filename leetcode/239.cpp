#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 单调队列
        // 一个窗口中，在左边且值小的数是毫无用处的
        // 因为在右边的活得久，值也大
        // 因此维护一个单调队列，存下标
        // 我们要保证这个队列存的下标对应的数是递减的
        // 因为如果右边的下标(j)比左边的(i)对应的数更大，则说明在nums中，
        // 有 j>i 且 nums[j]>nums[i]
        // 那么i就是无用的，需要从队列中删掉
        // 最终，队列左边的数就是当前窗口的最大值

        deque<int> dq; // 存idx
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() < i + 1 - k)
            {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
