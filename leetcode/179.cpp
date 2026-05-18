#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    class cmp
    {
    public:
        bool operator()(string s1, string s2)
        {
            return s1 + s2 > s2 + s1;
        }
    };

    string
    largestNumber(vector<int> &nums)
    {
        string ans;
        vector<string> strs;
        for (auto i : nums)
        {
            strs.push_back(to_string(i));
        }
        sort(strs.begin(), strs.end(), cmp());
        for (auto s : strs)
        {
            ans += s;
        }
        if (ans.front() == '0')
        {
            ans.resize(1);
        }
        return ans;
    }
};
