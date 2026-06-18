#include <bits/stdc++.h>
using namespace std;

// 快速判断两个单词是否有公共字母:
// 位运算获取每个单词的掩码
// 取低26位操作，每一位分别代表a-z是否出现
// 最终取&就可以知道有没有公共字母

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        auto flags = vector<int>(26);
        int tmp = 1;
        for (int i = 0; i < 26; i++)
        {
            flags[i] = tmp;
            tmp <<= 1;
        }

        int n = words.size();
        vector<int> masks(n, 0);
        for (int i = 0; i < n; i++)
        {
            auto s = words[i];
            for (auto c : s)
            {
                masks[i] |= flags[c - 'a'];
            }
        }
        int max_p = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((masks[i] & masks[j]) == 0)
                {
                    int p = words[i].size() * words[j].size();
                    max_p = max(max_p, p);
                }
            }
        }
        return max_p;
    }
};
