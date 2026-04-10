#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int cur = 0;
        int max = 0;

        while (r > l)
        {
            int min_is_left = height[l] <= height[r] ? 1 : 0;
            cur = (r - l) * min(height[l], height[r]);
            if (cur > max)
            {
                max = cur;
            }
            if (min_is_left)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return max;
    }
};
