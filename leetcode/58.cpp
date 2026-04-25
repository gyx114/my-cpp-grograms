#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int cnt = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if (*it == ' ' && cnt != 0)
            {
                return cnt;
            }
            else if (*it != ' ')
                cnt++;
        }
        return cnt;
    }
};
