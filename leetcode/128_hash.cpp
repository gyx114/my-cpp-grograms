#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        unordered_set<int> st;
        st.insert(nums.begin(), nums.end());
        int len = 1;
        int maxlen = 1;

        // 除了删除已遍历元素，还可以只从下限(x-1不在set中)开始遍历
        // 详见官方题解
        while (!st.empty())
        {
            auto i = *(st.begin());
            int tmp = i;
            while (st.count(tmp - 1))
            {
                st.erase(tmp - 1);
                len++;
                tmp--;
            }

            tmp = i;
            while (st.count(tmp + 1))
            {
                st.erase(tmp + 1);
                len++;
                tmp++;
            }
            st.erase(tmp);
            maxlen = max(maxlen, len);
            len = 1;
        }
        return maxlen;
    }
};
