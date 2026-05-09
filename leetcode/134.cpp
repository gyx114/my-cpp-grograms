#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int idx = 0;
        int total_sum = 0;
        int total_sum_to_i = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int delta = gas[i] - cost[i];
            total_sum += delta;
            if (delta < 0 && total_sum - total_sum_to_i < 0)
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
