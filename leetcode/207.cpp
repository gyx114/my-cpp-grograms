#include <bits/stdc++.h>
using namespace std;
// 拓扑排序
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        unordered_map<int, unordered_set<int>> outs;
        unordered_map<int, unordered_set<int>> ins;
        for (auto v : p)
        {
            outs[v[0]].insert(v[1]);
            ins[v[1]].insert(v[0]);
        }
        int ok_cnt = 0;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!ins.count(i))
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
                ins[o].erase(x);
                if (ins[o].empty())
                {
                    q.push(o);
                }
            }
        }
        return ok_cnt == n;
    }
};
