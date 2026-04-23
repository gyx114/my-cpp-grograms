#include <bits/stdc++.h>
using namespace std;

// just math
// 通过数学化为求前缀和

class Solution
{
public:
    unordered_map<int, vector<long long>> mp;
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> ans(n);

        for (int i = 0; i < n; i++)
        {
            if (mp[nums[i]].empty())
            {
                mp[nums[i]].push_back(i);
            }
            else
            {
                long long x = mp[nums[i]].back();
                mp[nums[i]].push_back(i + x);
            }
        }
        for (auto p : mp)
        {
            int x = p.first;
            vector<long long> sn = p.second;
            for (int k = 0; k < sn.size(); k++)
            {
                int n = sn.size();
                long long ak =
                    k == 0 ? sn[0] : (sn[k] - sn[k - 1]);
                long long tmp =
                    (2 * k + 2 - n) * ak - 2 * sn[k] + sn[n - 1];

                ans[ak] = tmp;
            }
        }
        return ans;
    }
};
