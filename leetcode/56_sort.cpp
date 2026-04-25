#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto i : intervals)
        {
            if (ans.empty())
            {
                ans.push_back(move(i));
            }
            else if (i[0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
            else
            {
                ans.push_back(move(i));
            }
        }
        return ans;
    }
};
