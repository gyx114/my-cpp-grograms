#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        // 26进制->10进制
        int ans = 0;
        for (auto c : columnTitle)
        {
            int i = c - 'A';
            ans = ans * 26 + i + 1;
        }
        return ans;
    }
};
