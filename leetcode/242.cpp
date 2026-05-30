#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (mp.count(t[i]) && mp[t[i]] > 0)
            {
                mp[t[i]]--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
