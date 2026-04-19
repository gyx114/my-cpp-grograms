#include <bits/stdc++.h>
using namespace std;

// 双指针

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums2.size() && i < nums1.size(); j++)
        {

            if (nums1[i] <= nums2[j])
            {
                ans = max<int>(ans, (j - i));
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
