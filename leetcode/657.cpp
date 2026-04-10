#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int y = 0;
        int x = 0;
        for (auto c : moves)
        {
            if (c == 'U')
            {
                y++;
            }
            else if (c == 'D')
            {
                y--;
            }
            else if (c == 'L')
            {
                x--;
            }
            else
            {
                x++;
            }
        }
        return x == 0 && y == 0;
    }
};
