#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {

        if (x == 0)
        {
            return 0;
        }
        else if (x <= 3)
        {
            return 1;
        }
        else if (x <= 8)
        {
            return 2;
        }
        else
        {
            long long l = 0;
            long long r = x / 2;
            long long mid = (l + r) / 2;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (mid * mid > x)
                {
                    r = mid - 1;
                }
                else
                {
                    if ((mid + 1) * (mid + 1) <= x)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
        }
        return 0;
    }
};
