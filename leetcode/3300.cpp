#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void replace(int &x)
    {
        int tmp = x;
        int ans = 0;
        while (tmp)
        {
            ans += tmp % 10;
            tmp /= 10;
        }
        x = ans;
    }

    int minElement(vector<int> &nums)
    {
        int ans = INT_MAX;
        for (auto &x : nums)
        {
            replace(x);
            ans = min(ans, x);
        }
        return ans;
    }
};
