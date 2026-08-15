#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        vector<int> cnt(26, 0);
        int max_len = 0;
        // 滑动窗口
        int l = 0;
        int r = 0;
        while (r < n)
        {
            int idx = s[r] - 'a';
            cnt[idx]++;
            while (cnt[idx] > 2)
            {
                cnt[s[l] - 'a']--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};
