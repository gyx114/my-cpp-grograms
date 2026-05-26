#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        int n = s.length();
        unordered_map<string, int> mp;
        for (int i = 0; i <= n - 10; i++)
        {
            string sub = s.substr(i, 10);
            if (mp[sub] == 1)
            {
                mp[sub]++;
                ans.push_back(move(sub));
            }
            else if (mp[sub] == 0)
            {
                mp[sub]++;
            }
        }
        return ans;
    }
};
