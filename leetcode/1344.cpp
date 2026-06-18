#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double a1 = (double)minutes / 60 * 360;
        double a2 = (double)hour / 12 * 360 + (double)minutes / 60 * (360 / 12.0);
        return abs(a1 - a2) <= 180 ? abs(a1 - a2) : 360 - abs(a1 - a2);
    }
};
