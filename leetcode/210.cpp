#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &p)
    {
        vector<vector<int>> outs(n);
        vector<int> indegrees(n, 0);
        for (auto pr : p)
        {
            outs[pr[1]].push_back(pr[0]);
            indegrees[pr[0]]++;
        }
        vector<int> ans;
        ans.reserve(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            ans.push_back(x);
            for (auto o : outs[x])
            {
                indegrees[o]--;
                if (indegrees[o] == 0)
                {
                    q.push(o);
                }
            }
        }
        if (ans.size() == n)
        {
            return ans;
        }
        else
        {
            return vector<int>();
        }
    }
};
