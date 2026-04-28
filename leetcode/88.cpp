#include <bits/stdc++.h>
using namespace std;
// 后入，避免从前面归并时覆盖元素
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
        {
            return;
        }
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (k >= 0)
        {
            if (i >= 0 && j >= 0)
            {
                if (nums1[i] > nums2[j])
                {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                }
                else if (nums1[i] <= nums2[j])
                {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
            else
            {
                if (i >= 0 && j < 0)
                {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                }
                else
                {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                }
            }
        }
    }
};
