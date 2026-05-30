#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 其他元素都出现3次
        // 考虑对每一位二进制累加
        // 三个相同元素的某一位累加，和为0或3，都是3的倍数
        // 剔除掉那个单独元素，对每一位求和，都是3的倍数
        // 加上那个单独元素之后对3取余，就是那个单独元素的二进制位

        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            int tmp = 0;

            for (auto &n : nums)
            {
                int x = n & (int)0b10000000000000000000000000000000;
                if (x == 0)
                {
                    tmp += 0;
                }
                else
                {
                    tmp += 1;
                }
                n <<= 1;
            }
            tmp %= 3;
            ans <<= 1;
            ans += tmp;
        }
        return ans;
    }
};
