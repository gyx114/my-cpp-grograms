#include <bits/stdc++.h>
using namespace std;
// 拓扑排序
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        vector<vector<int>> outs(n);
        vector<int> indegrees(n, 0);
        for (auto v : p)
        {
            indegrees[v[1]]++;
            outs[v[0]].push_back(v[1]);
        }
        int ok_cnt = 0;
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
            ok_cnt++;
            q.pop();
            for (auto o : outs[x])
            {
                indegrees[o]--;
                if (indegrees[o] == 0)
                {
                    q.push(o);
                }
            }
        }
        return ok_cnt == n;
    }
};
