#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int l1 = s.length();
        int l2 = goal.length();
        if (l1 != l2)
        {
            return false;
        }
        int is_ok = 1;
        for (int i = 0; i < l1; i++)
        {
            is_ok = 1;
            for (int j = 0; j < l1; j++)
            {
                int idx1 = (i + j) % l1;
                if (s[idx1] != goal[j])
                {
                    is_ok = 0;
                    break;
                }
            }
            if (is_ok)
            {
                break;
            }
        }
        return is_ok;
    }
};
