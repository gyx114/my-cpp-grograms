#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        // 10进制->26进制
        string ans;
        int tmp = columnNumber;
        while (tmp)
        {
            tmp--;
            ans.push_back('A' + tmp % 26);
            tmp /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
