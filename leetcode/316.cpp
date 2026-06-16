#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> cnt(26);     // 每个字母还剩几个没处理
        vector<int> visited(26); // 某字母是否已加入st
        // 注意，数组大小是26(26个英文字母)而不是s的长度
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
        string st; // 递增栈
        for (auto c : s)
        {
            int idx = c - 'a';
            if (!visited[idx]) // 没加入st才有操作的必要,加入了直接跳过
            {
                while (!st.empty() && c <= st.back() &&
                       cnt[st.back() - 'a'] > 0 // 保证还有备用字符,后面还能加入
                )
                {
                    visited[st.back() - 'a'] = 0;
                    st.pop_back();
                }
                st += c;
                visited[idx] = 1;
            }
            cnt[idx]--; // 不管加没加入st,都处理了这个字符
        }

        return st;
    }
};
