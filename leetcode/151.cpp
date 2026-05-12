#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int i1 = 0;
        int i2 = 0;
        while (true)
        {
            if (i2 >= s.size())
            {
                break;
            }
            while (s[i2] == ' ')
            {
                i2 = s.erase(s.begin() + i2) - s.begin();
            }
            i1 = i2;

            while (s[i2] != ' ' && i2 != s.size())
            {
                i2++;
            }
            reverse(s.begin() + i1, s.begin() + i2);
            if (i2 + 1 < s.size())
            {
                i2++;
                i1 = i2;
            }
            else
            {
                break;
            }
        }
        if (s.back() == ' ')
        {
            s.pop_back();
        }
        return s;
    }
};
