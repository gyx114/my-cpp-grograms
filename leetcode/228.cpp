#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        vector<string> ans;
        if (nums.empty())
        {
            return ans;
        }
        string tmp;
        int beg = nums[0];
        int end = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                end = nums[i];
            }
            else
            {
                if (end > beg)
                {
                    tmp += to_string(beg);
                    tmp += "->";
                    tmp += to_string(end);

                    ans.push_back(move(tmp));
                    tmp.clear();
                    beg = end = nums[i];
                }
                else
                {
                    tmp += to_string(beg);
                    ans.push_back(move(tmp));
                    tmp.clear();
                    beg = end = nums[i];
                }
            }
        }

        // 收尾
        if (end > beg)
        {
            tmp += to_string(beg);
            tmp += "->";
            tmp += to_string(end);

            ans.push_back(move(tmp));
            tmp.clear();
        }
        else
        {
            tmp += to_string(beg);
            ans.push_back(move(tmp));
            tmp.clear();
        }
        return ans;
    }
};
