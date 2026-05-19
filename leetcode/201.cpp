#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 即寻找公共前缀，后面以0填充
    int rangeBitwiseAnd(int m, int n)
    {
        while (m < n)
        {
            // 抹去最右边的 1
            n = n & (n - 1);
        }
        return n;
    }
};
