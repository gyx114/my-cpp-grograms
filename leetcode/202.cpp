#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 只能是6,8,10的勾股定理
    bool isHappy(int n)
    {
        unordered_set<int> visited;
        while (true)
        {
            int tmp = 0;
            while (n)
            {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }

            if (tmp == 1)
            {
                return true;
            }
            if (visited.count(tmp))
            {
                return false;
            }
            visited.insert(tmp);
            n = tmp;
        }
    }
};
