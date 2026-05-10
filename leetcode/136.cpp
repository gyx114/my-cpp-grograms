#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 很骚的思路：位运算
    //^(异或)性质：
    // 对于任意数a,有  a^0=a   a^a=0
    // 把数组全异或起来,成对的都异或成了0
    // 0与落单的异或，结果就是那个落单的
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto i : nums)
        {
            ans ^= i;
        }
        return ans;
    }
};
