#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> ans_idx; // 排序后的字符串:同类字符串数组在ans中的下标

        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());

            if (ans_idx.count(s))
            {
                ans[ans_idx[s]].push_back(move(strs[i]));
            }
            else
            {
                ans_idx[s] = ans.size();
                vector<string> hello;
                hello.push_back(move(strs[i]));
                ans.push_back(move(hello));
            }
        }
        return ans;
    }
};
