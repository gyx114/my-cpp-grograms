#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
        {
            words.push_back(move(tmp));
        }
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int n = pattern.size();
        int n1 = words.size();
        if (n != n1)
        {
            return false;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp1.count(pattern[i]) && mp2.count(words[i]))
            {
                if (mp1[pattern[i]] != words[i] || mp2[words[i]] != pattern[i])
                {
                    return false;
                }
            }
            else if (!mp1.count(pattern[i]) && !mp2.count(words[i]))
            {
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
