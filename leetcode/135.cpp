#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int total = 1;
        int downidx = 0;
        int down_begin_num = 1;
        int pre = 1;
        int record = 0;
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                pre++;
                total += pre;
                downidx = i;
                record = 0;
                down_begin_num = pre;
            }
            else if (ratings[i] == ratings[i - 1])
            {
                total += 1;
                pre = 1;
                downidx = i;
                record = 0;
                down_begin_num = pre;
            }
            else
            {
                pre = 1;
                total += i - downidx;
                record++;
                if (record == down_begin_num)
                {
                    down_begin_num++;
                    total++;
                }
            }
        }
        return total;
    }
};
