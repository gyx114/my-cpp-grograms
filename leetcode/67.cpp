#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (a.length() < b.length())
        {
            a.swap(b);
        }
        int len1 = a.length();
        int len2 = b.length();
        string ans_reverse;
        int tmp = 0;
        int remain = 0;
        int jinwei = 0;
        for (int i = 0; i < len1; i++)
        {
            if (i >= len2)
            {
                tmp = a[len1 - 1 - i] - '0' + jinwei;
                remain = tmp % 2;
                jinwei = tmp / 2;
                ans_reverse.push_back(remain + '0');
            }
            else
            {
                tmp = a[len1 - 1 - i] - '0' + b[len2 - 1 - i] - '0' + jinwei;
                remain = tmp % 2;
                jinwei = tmp / 2;
                ans_reverse.push_back(remain + '0');
            }
        }
        if (jinwei)
        {
            ans_reverse.push_back(jinwei + '0');
        }
        string ans(ans_reverse.rbegin(), ans_reverse.rend());
        return ans;
    }
};
