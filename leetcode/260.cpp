#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> ans(2, 0);
        unsigned tmp = 0;
        for (auto i : nums)
        {
            tmp ^= i;
        }
        // 此时tmp为那两个数字的异或

        tmp = tmp & (-tmp); // 取出最低位的1
        // 说明那两个数字在这一位上不同,一个0一个1
        // 把数组分两部分:
        // 一部分在这一位上是1
        // 另一部分在这一位上是0
        for (auto i : nums)
        {
            if (i & tmp)
            { // 在这一位是1
                ans[0] ^= i;
            }
            else
            { // 在这一位是0
                ans[1] ^= i;
            }
        }
        return ans;
    }
};
