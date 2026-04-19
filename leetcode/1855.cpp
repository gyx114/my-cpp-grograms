#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums2, int lft, int rht, int n1)
    {

        while (lft < rht)
        {
            int mid = (lft + rht) / 2;
            if (nums2[mid] < n1)
            {
                rht = mid - 1;
            }

            else
            {
                if (nums2[mid + 1] >= n1)
                {
                    lft = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
        }

        return lft;
    }

    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {

        int max = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int idx2 = search(nums2, i, nums2.size() - 1, nums1[i]);
            int delta = idx2 - i;
            max = delta > max ? delta : max;
        }
        return max;
    }
};
