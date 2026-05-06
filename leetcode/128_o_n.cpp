#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int find(unordered_map<int, int> &father, int x)
    {
        if (father[x] != x)
        {
            return father[x] = find(father, father[x]);
        }
        return x;
    }
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        unordered_map<int, int> father; // num:father
        unordered_map<int, int> mp;     // num:idx
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (!mp.count(num))
            {
                mp[num] = i;
                father[num] = num;
                if (mp.count(num + 1) && mp.count(num - 1))
                {
                    father[num - 1] = find(father, num + 1);
                    father[num] = find(father, num + 1);
                }
                else if (mp.count(num + 1))
                {
                    father[num] = find(father, num + 1);
                }
                else if (mp.count(num - 1))
                {
                    father[num - 1] = num;
                }
            }
        }
        int max_len = 1;
        for (auto i : nums)
        {
            max_len = max(max_len, find(father, i) - i + 1);
        }
        return max_len;
    }
};
