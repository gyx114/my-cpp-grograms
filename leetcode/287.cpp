#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // 建图，i->nums[i]
        // 必有环，环入口即是重复数

        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
