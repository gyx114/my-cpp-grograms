#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // 易证,最多有两个符合要求
    // 三方混战，保两个数n1,n2
    // 遍历nums，如果某数既不是n1也不是n2，则同归于尽
    // 最后检查n1和n2是否符合要求
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int n1 = 0;
        int cnt1 = 0;
        int n2 = 0;
        int cnt2 = 0;
        for (auto i : nums)
        {
            if (i == n1)
            {
                cnt1++;
            }
            else if (i == n2)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                n1 = i;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                n2 = i;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for (auto i : nums)
        {
            if (i == n1)
            {
                cnt1++;
            }
            else if (i == n2)
            {
                cnt2++;
            }
        }
        if (cnt1 > n / 3)
        {
            ans.push_back(n1);
        }
        if (cnt2 > n / 3)
        {
            ans.push_back(n2);
        }
        return ans;
    }
};
