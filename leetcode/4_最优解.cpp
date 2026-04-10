#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 > len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int total_len = len1 + len2;
        int is_two;
        int left_cnt;
        if (total_len % 2 == 0)
        {
            is_two = 1;
            left_cnt = total_len / 2;
        }
        else
        {
            is_two = 0;
            left_cnt = (total_len + 1) / 2;
        }

        int left = 0;
        int right = len1;
        while (left <= right)
        {
            // 在第一个中取几个
            int n1 = (left + right) / 2;
            // 在第二个中取几个
            int n2 = left_cnt - n1;

            //     我们在每个数组中画一个"分割线",_left表示线左边的数，_right表示右边的数
            //     例如：nums1: 1 2 4 7 8 中我要取3个，则画线：
            //         nums1:  1 2 4  ▎ 7 8
            //      则nums1_left就是4，nums1_right就是7

            // 边界处理
            int nums1_left = (n1 == 0 ? INT_MIN : nums1[n1 - 1]); // 取0个
            int nums1_right = (n1 == len1 ? INT_MAX : nums1[n1]); // 全取
            int nums2_left = (n2 == 0 ? INT_MIN : nums2[n2 - 1]);
            int nums2_right = (n2 == len2 ? INT_MAX : nums2[n2]);

            if (nums1_left > nums2_right)
            {
                right = n1 - 1;
            }
            else if (nums2_left > nums1_right)
            {
                left = n1 + 1;
            }
            else
            {
                if (is_two)
                {
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
                }
                else
                {
                    return max(nums1_left, nums2_left);
                }
            }
        }
        return 0.0;
    }
};
