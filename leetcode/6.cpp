#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {

        int len = s.length();

        int T = numRows == 1 ? 1 : 2 * (numRows - 1);

        string ans;

        int idx = 0;
        while (idx <= len - 1)
        {
            ans.push_back(s[idx]);
            idx += T;
        }

        for (int i = 2; i < numRows; i++)
        {
            int idx1 = i - 1;
            int idx2 = i + 2 * (numRows - i) - 1;
            bool flag = true;
            // true表示用idx1
            // false表示用idx2
            while (true)
            {
                if (flag && idx1 >= len)
                {
                    break;
                }
                else if (!flag && idx2 >= len)
                {
                    break;
                }

                else if (flag)
                {
                    ans.push_back(s[idx1]);
                    idx1 += T;
                    flag = !flag;
                }
                else
                {
                    ans.push_back(s[idx2]);
                    idx2 += T;
                    flag = !flag;
                }
            }
        }
        if (numRows > 1)
        {
            idx = numRows - 1;
            while (idx <= len - 1)
            {
                ans.push_back(s[idx]);
                idx += T;
            }
        }

        return ans;
    }
};
