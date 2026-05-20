#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            auto si = s[i];
            auto ti = t[i];
            if (mp1.count(si))
            {
                if (mp1[si] != ti)
                {
                    return false;
                }
            }
            else
            {
                if (mp2.count(ti))
                {
                    if (mp2[ti] != si)
                    {
                        return false;
                    }
                }
                else
                {
                    mp1[si] = ti;
                    mp2[ti] = si;
                }
            }
        }
        return true;
    }
};
