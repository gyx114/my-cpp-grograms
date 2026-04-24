#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int r = 0;
        int _ = 0;
        for (auto i : moves)
        {
            if (i == 'R')
                r++;
            else if (i == 'L')
                r--;
            else
                _++;
        }
        if (r >= 0)
        {
            return r + _;
        }
        else
        {
            return -r + _;
        }
    }
};
