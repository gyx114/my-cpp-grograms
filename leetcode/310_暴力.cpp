#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> neighbors(n);
        for (auto p : edges)
        {
            neighbors[p[0]].push_back(p[1]);
            neighbors[p[1]].push_back(p[0]);
        }
        int min_h = INT_MAX;
        vector<int> heights(n, -1);
        for (int i = 0; i < n; i++)
        {
            int h = -1;
            queue<int> q;
            q.push(i);
            int sz = 1;
            unordered_set<int> visited;
            while (sz)
            {
                h++;
                for (int j = 0; j < sz; j++)
                {
                    int x = q.front();
                    visited.insert(x);
                    q.pop();
                    for (auto n : neighbors[x])
                    {
                        if (!visited.count(n))
                            q.push(n);
                    }
                }
                sz = q.size();
            }
            heights[i] = h;
            min_h = min(min_h, h);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] == min_h)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
