#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        multimap<int, int> mp;
        for (auto i : intervals)
        {
            mp.emplace(i[0], i[1]);
        }
        for (auto it = mp.begin(), pre = mp.begin(); it != mp.end();)
        {
            if (it == mp.begin())
            {
                pre = it++;
            }
            else if (it->first <= pre->second)
            {
                int maxend = max(it->second, pre->second);
                pre->second = maxend;
                it = mp.erase(it);
            }
            else
            {
                pre = it++;
            }
        }
        vector<vector<int>> ans;
        for (auto i : mp)
        {
            vector<int> tmp = {i.first, i.second};
            ans.push_back(move(tmp));
        }
        return ans;
    }
};
