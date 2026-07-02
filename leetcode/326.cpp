#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // 本质打表
        return n > 0 && 1162261467 % n == 0;
    }
};
