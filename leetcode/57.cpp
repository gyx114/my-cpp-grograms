#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void insert_single(vector<vector<int>> &ans, vector<int> &range)
    {
        if (ans.empty())
        {
            ans.push_back(move(range));
        }
        else if (range[0] >= ans.back()[0] && range[0] <= ans.back()[1])
        {
            ans.back()[1] = max(ans.back()[1], range[1]);
        }
        else
        {
            ans.push_back(move(range));
        }
    }
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        if (intervals.size() == 0)
        {
            ans.push_back(move(newInterval));
            return ans;
        }
        int n = intervals.size();
        int l = 0;
        int r = n - 1;
        int idx = 0; // 可能需要被合并的最小下标
        while (true)
        {
            int mid = (l + r) / 2;
            if (intervals[mid][0] > newInterval[0])
            {
                if (mid == 0)
                {
                    idx = -1;
                    break;
                }
                if (newInterval[0] >= intervals[mid - 1][0])
                {
                    idx = mid - 1;
                    break;
                }

                else
                {
                    r = mid - 1;
                }
            }
            else if (intervals[mid][0] == newInterval[0])
            {
                idx = mid;
                break;
            }
            else
            {
                if (mid == n - 1)
                {
                    idx = n - 1;
                    break;
                }
                if (intervals[mid + 1][0] >= newInterval[0])
                {
                    idx = mid;
                    break;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        if (idx == -1)
        {
            ans.push_back(move(newInterval));
        }

        for (int i = 0; i < intervals.size(); i++)
        {
            if (i <= idx)
            {
                ans.push_back(move(intervals[i]));
                if (i == idx)
                {
                    insert_single(ans, newInterval);
                }
            }
            else
            {
                insert_single(ans, intervals[i]);
            }
        }

        return ans;
    }
};
