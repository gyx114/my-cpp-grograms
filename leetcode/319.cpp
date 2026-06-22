#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 第k个灯泡:若k有奇数个约数，最终是亮的
    // 设有一个约数是x,则k/x也是约数
    // 如果k是完全平方数,则除了sqrt(x)都成对出现，有奇数个约数
    // 如果k不是完全平方数，有偶数个
    // 因此只需求出[1,n]内有多少完全平方数
    // 即有 sqrt(n) 个

    int bulbSwitch(int n)
    {
        return (int)sqrt(n);
    }
};
