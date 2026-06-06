#include <bits/stdc++.h>
using namespace std;
// 贪心+二分
// 在遍历过程中不断更新最长长度或者某一长度对应的最小末尾元素
// 最终遍历完成时即得到最长长度
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> len2min_elem(n + 1); // 同一子序列长度i对应的最小末尾元素
        int cur_max_len = 1;
        len2min_elem[1] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > len2min_elem[cur_max_len])
            {
                len2min_elem[++cur_max_len] = nums[i];
            }
            else
            {
                auto it = lower_bound(len2min_elem.begin() + 1, len2min_elem.begin() + cur_max_len + 1, nums[i]);
                int len = it - len2min_elem.begin();
                len2min_elem[len] = nums[i];
            }
        }
        return cur_max_len;
    }
};
