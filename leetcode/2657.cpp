#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<int> ans(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] += ans[i - 1];
            }
            if (mp.count(b[i]))
            {
                if (mp[b[i]] <= i)
                {
                    ans[i]++;
                }
                else
                {
                    ans[mp[b[i]]]++;
                }
            }
        }
        return ans;
    }
};
