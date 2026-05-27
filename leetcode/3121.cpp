#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int cnt = 0;
        unordered_map<char, int> mp;
        vector<char> capitals;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            auto wi = word[i];
            if (wi >= 'a' && wi <= 'z')
            {
                mp[wi] = i;
            }
            else if (!mp.count(wi))
            {
                mp[wi] = i;
                capitals.push_back(wi);
            }
        }
        for (auto cap : capitals)
        {
            if (mp.count(cap + 'a' - 'A') && mp[cap] > mp[cap + 'a' - 'A'])
            {
                cnt++;
            }
        }
        return cnt;
    }
};
