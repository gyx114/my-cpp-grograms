#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int sum = strs.size();
        sort(strs.begin(), strs.end());
        string ans;
        string &s1 = strs[0];
        string &s2 = strs[sum - 1];
        for (int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if (s1[i] == s2[i])
            {
                ans.push_back(s1[i]);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};
