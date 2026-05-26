#include <bits/stdc++.h>
using namespace std;

// 使用位运算快捷进行滑动窗口操作
// 同时由于只有acgt四个字符，可以用2位二进制来代表每个字符
// 又窗口长度为10，需要20位，一个int足够
// 滑动窗口时无需取子串以及拷贝，时间上是o(n)的

// 位运算在特定问题（字符种类少）中威力巨大

class Solution
{
public:
    const int k = 0x3FFFF;
    enum
    {
        a,
        c,
        g,
        t
    };
    unordered_map<int, char> itc = {{a, 'A'}, {c, 'C'}, {g, 'G'}, {t, 'T'}};
    int char_to_int(char x)
    {
        switch (x)
        {
        case 'A':
            return a;
            break;
        case 'C':
            return c;
            break;
        case 'G':
            return g;
            break;
        case 'T':
            return t;
            break;
        }
        return 0;
    }
    void push_back(int &hash, char x)
    {
        int bk = char_to_int(x);
        hash <<= 2;
        hash += bk;
    }
    void erase_front(int &hash)
    {
        hash = hash & k;
    }
    vector<string> findRepeatedDnaSequences(string s)
    {
        // 字符串哈希 A:00 C:01 G:10 T:11
        unordered_map<int, int> mp;
        vector<string> ans;
        int n = s.length();
        if (n <= 10)
        {
            return ans;
        }
        int hash = 0;
        for (int i = 0; i < 10; i++)
        {
            push_back(hash, s[i]);
        }
        mp[hash] = 1;
        for (int i = 10; i < n; i++)
        {
            erase_front(hash);
            push_back(hash, s[i]);
            if (mp[hash] == 1)
            {
                string ss;
                auto temp = hash;
                for (int j = 0; j < 10; j++)
                {
                    ss += itc[temp & 3];
                    temp >>= 2;
                }
                reverse(ss.begin(), ss.end());
                ans.push_back(move(ss));
            }

            mp[hash]++;
        }
        return ans;
    }
};
