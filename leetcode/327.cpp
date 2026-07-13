#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int cnt_pairs(int l, int r, vector<ll> &pre, int lower, int upper)
    // 做两件事：统计[l,r]区间里符合要求的下标对，并顺便给pre数组排序(归并排序)
    {
        if (r <= l)
        {
            return 0;
        }

        int mid = l + (r - l) / 2;

        // 找左半边的，顺便把左半边排序
        int cnt_l = cnt_pairs(l, mid, pre, lower, upper);

        // 找右半边的，顺便把右半边排序
        int cnt_r = cnt_pairs(mid + 1, r, pre, lower, upper);

        int cnt_mid = 0;
        // 找跨越中点的,此时pre数组左右半边都有序，考虑使用双指针,比lower_bound和upper_bound快一点
        int l_l = l;
        int l_r = l;
        for (int i = mid + 1; i <= r; i++)
        // 固定右半边下标为i，在左边找两个边界
        {
            while (l_l <= mid && pre[l_l] < pre[i] - upper)
            {
                l_l++;
            }
            while (l_r <= mid && pre[l_r] <= pre[i] - lower)
            {
                l_r++;
            }
            cnt_mid += max(0, l_r - l_l);
        }

        // pre数组自身归并排序
        int i1 = l;
        int i2 = mid + 1;
        int cnt = 0;
        vector<ll> tmp(r - l + 1);
        while (i1 <= mid && i2 <= r)
        {
            if (pre[i1] < pre[i2])
            {
                tmp[cnt++] = pre[i1++];
            }
            else
            {
                tmp[cnt++] = pre[i2++];
            }
        }
        while (i1 <= mid)
        {
            tmp[cnt++] = pre[i1++];
        }
        while (i2 <= r)
        {
            tmp[cnt++] = pre[i2++];
        }

        for (int i = 0; i < tmp.size(); i++)
        {
            pre[l + i] = tmp[i];
        }

        return cnt_l + cnt_mid + cnt_r;
    }

    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int cnt = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
        return cnt_pairs(0, n, pre, lower, upper);
    }
};
