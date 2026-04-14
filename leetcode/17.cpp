#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> plus(string &s1, string &s2)
    {
        vector<string> tmp;
        if (s2.length() == 0)
        {
            for (int i = 0; i < s1.length(); i++)
            {
                string gyx;
                gyx.push_back(s1[i]);
                tmp.push_back(gyx);
            }
            return tmp;
        }

        for (int j = 0; j < s2.length(); j++)
        {
            string s = s1;

            s.push_back(s2[j]);
            tmp.push_back(s);
        }

        return tmp;
    }

    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();

        unordered_map<char, string> mp;
        mp.emplace('2', "abc");
        mp.emplace('3', "def");
        mp.emplace('4', "ghi");
        mp.emplace('5', "jkl");
        mp.emplace('6', "mno");
        mp.emplace('7', "pqrs");
        mp.emplace('8', "tuv");
        mp.emplace('9', "wxyz");
        vector<string> tmp;
        vector<string> ans;
        string kong;

        ans = plus(mp[digits[0]], kong);
        if (n == 1)
        {
            return ans;
        }
        tmp = ans;
        for (int i = 1; i <= n - 1; i++)
        {
            tmp.clear();
            for (auto s : ans)
            {
                auto vs = plus(s, mp[digits[i]]);

                tmp.insert(tmp.end(), vs.begin(), vs.end());
            }
            ans = tmp;
        }
        return ans;
    }
};
