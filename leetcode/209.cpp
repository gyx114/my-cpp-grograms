#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> s(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + nums[i - 1];
            int l = 0;
            int r = i - 1;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (s[i] - s[mid] >= target)
                {
                    if (s[i] - s[mid + 1] >= target)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        ans = min(ans, i - mid);
                        break;
                    }
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        if (ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};
