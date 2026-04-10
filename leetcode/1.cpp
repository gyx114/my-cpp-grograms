#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> solution;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {

            if (m.count(target - nums[i]))
            {
                int x = m[target - nums[i]];
                solution.push_back(i);
                solution.push_back(x);
                break;
            }
            m[nums[i]] = i;
        }

        return solution;
    }
};
