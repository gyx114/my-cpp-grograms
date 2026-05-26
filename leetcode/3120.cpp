#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        unordered_map<char, int> mp;
        int cnt = 0;
        unordered_set<char> used;
        for (int i = 0; i < word.size(); i++)
        {
            auto wi = word[i];
            mp[wi] = i;
            if (wi >= 'A' && wi <= 'Z' && mp.count(wi + 'a' - 'A') && !used.count(wi))
            {
                cnt++;
                used.insert(wi);
            }
            else if (wi >= 'a' && wi <= 'z' && mp.count(wi + 'A' - 'a') && !used.count(wi + 'A' - 'a'))
            {
                cnt++;
                used.insert(wi + 'A' - 'a');
            }
        }
        return cnt;
    }
};
