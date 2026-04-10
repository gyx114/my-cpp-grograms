#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int max = 0;
        int idx = 0;
        int len = s.length();
        int now = 0;

        int left = 0;

        while (idx < len)
        {
            if (!m.count(s[idx]) || m[s[idx]] < left)
            {
                m[s[idx]] = idx;
                idx++;
                now++;
            }
            else
            {
                if (now > max)
                {
                    max = now;
                }

                left = m[s[idx]] + 1;
                now = idx - left + 1;
                m[s[idx]] = idx;
                idx++;
            }
        }
        if (now > max)
            max = now;

        return max;
    }
};
