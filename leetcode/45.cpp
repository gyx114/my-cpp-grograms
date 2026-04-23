#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxPos = 0; // 当前位置能到达的最远处
        int n = nums.size();
        int end = 0;  // 当前步数下最远到哪
        int step = 0; // 步数
        for (int i = 0; i < n - 1; ++i)
        {
            if (maxPos >= i)
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end)
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};
