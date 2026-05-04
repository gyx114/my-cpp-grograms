#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp(i + 1, 1);
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    continue;
                }
                else
                {
                    tmp[j] = ans.back()[j - 1] + ans.back()[j];
                }
            }
            ans.push_back(move(tmp));
        }
        return ans;
    }
};
