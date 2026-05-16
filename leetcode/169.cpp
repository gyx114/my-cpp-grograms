#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // 同归于尽法
        // 让不同的两个数同归于尽
        // 则最后剩下的必然是"多数元素"
        int n = nums.size();
        int remain;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                remain = nums[i];
                cnt = 1;
            }
            else
            {
                if (nums[i] == remain)
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
            }
        }
        return remain;
    }
};
