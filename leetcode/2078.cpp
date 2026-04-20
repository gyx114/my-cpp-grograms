#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int i = 0;
        int j = colors.size() - 1;
        int ans = 1;
        while (j > i)
        {
            if (colors[i] != colors[j])
            {

                return j - i;
            }
            else
            {
                int ii = i + 1;
                int jj = j - 1;
                while (colors[jj] == colors[jj + 1] && colors[ii] == colors[ii - 1])
                {
                    ii++;
                    jj--;
                }
                if (colors[jj] == colors[jj + 1])
                {
                    i = ii;
                }
                else
                {
                    j = jj;
                }
            }
        }
        return ans;
    }
};
