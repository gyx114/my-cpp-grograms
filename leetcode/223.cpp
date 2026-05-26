#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        auto s1 = (ax2 - ax1) * (ay2 - ay1);
        auto s2 = (bx2 - bx1) * (by2 - by1);

        if (ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2)
        {
            return s1 + s2;
        }
        vector<int> xs = {ax1, ax2, bx1, bx2};
        vector<int> ys = {ay1, ay2, by1, by2};
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        auto repeted = (xs[2] - xs[1]) * (ys[2] - ys[1]);

        return s1 + s2 - repeted;
    }
};
