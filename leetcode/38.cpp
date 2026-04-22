#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void zip(string &s)
    {
        string tmp;
        int cnt = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                tmp.push_back('0' + cnt);
                tmp.push_back(s[i - 1]);
                cnt = 1;
            }
            if (i == s.length() - 1)
            {
                tmp.push_back('0' + cnt);
                tmp.push_back(s[i]);
            }
        }
        s.assign(tmp.begin(), tmp.end());
    }
    string countAndSay(int n)
    {
        string ans = "1";
        if (n == 1)
        {
            return ans;
        }
        ans = "11";
        for (int i = 3; i <= n; i++)
        {
            zip(ans);
        }
        return ans;
    }
};
