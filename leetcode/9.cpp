#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        stringstream ss;
        ss << x;
        string s;
        // s = ss.str();
        ss >> s;
        int len = s.length();
        for (int i = 0; i <= (len - 1) / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
