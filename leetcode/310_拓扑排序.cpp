#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 拓扑排序+剥洋葱
    // 每一次把一圈外层叶子(度数为1)剥去
    // 剥完一圈就更新leaves
    // 最终剩下的就是根(1个或2个)

    // 使用数组代替unordered_set记录neighbors,缓存友好
    // 然后不修改neighbors,而是修改degrees,没有额外复杂度
    // 这实际上比unordered_set快得多

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0};
        }
        vector<vector<int>> neighbors(n);
        vector<int> degrees(n);
        for (auto p : edges)
        {
            degrees[p[0]]++;
            degrees[p[1]]++;
            neighbors[p[0]].push_back(p[1]);
            neighbors[p[1]].push_back(p[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1)
            {
                leaves.push_back(i);
            }
        }
        int cnt = 0;
        vector<int> tmp;
        tmp.reserve(n);
        while (cnt < n - 2)
        {
            tmp.clear();
            for (auto x : leaves) // 保证一次剥完整一圈
            {
                cnt++;
                for (auto nb : neighbors[x])
                {
                    degrees[nb]--;
                    if (degrees[nb] == 1)
                    {
                        tmp.push_back(nb);
                    }
                }
            }
            leaves.swap(tmp);
        }
        return leaves;
    }
};
