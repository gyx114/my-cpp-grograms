#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canWinNim(int n)
    {
        // if (n <= 3)
        // {
        //     return true;
        // }
        // bool a = true;
        // bool b = true;
        // bool c = true;
        // int cur = 3;
        // while (cur != n)
        // {
        //     auto tmp = !a || !b || !c;
        //     a = b;
        //     b = c;
        //     c = tmp;
        //     cur++;
        // }
        // return c;

        // 赢赢赢输 赢赢赢输 循环
        return n % 4 != 0;
    }
};
