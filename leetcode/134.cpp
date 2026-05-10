#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int idx = 0;
        int total_sum = 0;      // 从0到i油量变化量
        int total_sum_to_i = 0; // 从0到idx-1油量变化量
        // total_sum - total_sum_to_i则代表idx到i油量变化，如果<0,说明目前的idx设置有问题
        for (int i = 0; i < gas.size(); i++)
        {
            total_sum += gas[i] - cost[i];
            if (total_sum - total_sum_to_i < 0)
            {
                idx = i + 1;
                total_sum_to_i = total_sum;
            }
        }
        if (idx >= gas.size() || total_sum < 0)
        {
            return -1;
        }
        return idx;
    }
};
