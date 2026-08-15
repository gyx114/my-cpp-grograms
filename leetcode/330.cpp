#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
#define ll long long
        ll max_to = 0;
        int cnt = 0;
        int idx = 0;
        // 思想：如果[1,x]都可以被表示，那再加入一个m,且要求m<=x+1，则可以表示[1,x+m]
        while (max_to < n)
        {
            ll cur = idx < nums.size() ? nums[idx] : LONG_LONG_MAX;
            if (cur <= max_to + 1)
            {
                max_to += cur;
                idx++;
            }
            else
            {
                max_to += max_to + 1; // nums里没有就加入max_to+1
                cnt++;
            }
        }
        return cnt;
    }
};
