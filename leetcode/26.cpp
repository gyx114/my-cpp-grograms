#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int total = nums.size();
        int cnt = 0;
        int pre = -1000;
        for (int i = 0; i < total; i++)
        {
            if (nums[i] != pre)
            {
                nums[cnt] = nums[i];
                cnt++;
                pre = nums[i];
            }
        }
        return cnt;
    }
};
