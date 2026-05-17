#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> &arr, int start, vector<int> &can_reach)
    {
        if (start < 0 || start >= arr.size())
        {
            return;
        }
        if (!can_reach[start])
        {

            can_reach[start] = true;
            dfs(arr, start + arr[start], can_reach);
            dfs(arr, start - arr[start], can_reach);
        }
    }

    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> can_reach(n, false);
        dfs(arr, start, can_reach);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0 && can_reach[i])
            {
                return true;
            }
        }
        return false;
    }
};
