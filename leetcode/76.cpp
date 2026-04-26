#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // 滑动窗口
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp;  // 存t的信息
        unordered_map<char, int> tmp; // 滑动窗口时记录窗口信息
        int needcnt = t.size();       // 还需要再加入几个必需字符
        int minlen = INT_MAX;
        string ans;
        deque<char> window; // 双端队列记录窗口信息，便于头尾增删
        for (auto c : t)
        {
            mp[c]++;
        }

        int l = 0;
        int r = 0;
        while (l < s.length() && !mp.count(s[l]))
        {
            l++; // 找一个合适的左边界
        }
        if (l == s.length())
        {
            return "";
        }
        r = l;
        while (r < s.length() && l < s.length())
        {
            if (mp.count(s[r])) // 右边界字符在t中
            {
                if (tmp[s[r]] < mp[s[r]])
                {
                    needcnt--; // 如果窗口中此字符数少于t中的数量，算一个必需字符
                }
                tmp[s[r]]++;
                window.push_back(s[r]);

                if (needcnt == 0) // 此窗口包含了t
                {
                    // 收缩一下左边界，剔除t中不存在的字符或者供大于求的字符

                    while (l <= r && (!mp.count(s[l]) || tmp[s[l]] > mp[s[l]]))
                    {
                        window.pop_front();
                        if (mp.count(s[l]))
                        {
                            tmp[s[l]]--;
                        }

                        l++;
                    }
                    // 比较，如果更小就更新ans和minlen
                    if (r - l + 1 < minlen)
                    {
                        minlen = r - l + 1;
                        ans = s.substr(l, minlen);
                    }

                    // 继续移动左边界，剔除一个必需字符以寻找其他解
                    if (l <= r && mp.count(s[l]))
                    {
                        tmp[s[l]]--;
                        if (tmp[s[l]] < mp[s[l]])
                        {
                            needcnt++;
                        }
                        window.pop_front();
                        l++;
                    }
                    // 依旧移动左边界找到一个必需字符
                    while (l <= r && !mp.count(s[l]))
                    {
                        if (!window.empty())
                        {
                            window.pop_front();
                        }
                        else
                        {
                            break;
                        } // windows空，不用继续找了
                        l++;
                    }
                }
            }
            else
            // 右边界字符不在t中，放入window
            {
                window.push_back(s[r]);
            }
            r++;
        }
        return ans;
    }
};
