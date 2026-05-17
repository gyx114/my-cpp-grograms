#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trailingZeroes(int n)
    {
        // 0只能由2*5得来
        // 偶数都有2为因子
        // 显然，以5为因子的数小于以2为因子的数
        // 找因子中有5的数字的个数
        int cnt = 0;
        for (int i = 1; i * 5 <= n; i++)
        {
            cnt++;
            int tmp = i * 5;
            while (tmp * 5 <= n)
            {
                cnt++;
                tmp *= 5;
            }
        }
        return cnt;
    }
};
