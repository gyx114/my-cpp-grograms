#include <bits/stdc++.h>
using namespace std;

class NumArray
{
#define lowbit(x) ((x) & (-x))
public:
    vector<int> tree;
    void add(int idx, int x)
    {
        int i = idx + 1;
        while (i < tree.size())
        {
            tree[i] += x;
            i += lowbit(i);
        }
    }
    int prefix(int i)
    {
        int idx = i + 1;
        if (idx == 0)
        {
            return 0;
        }
        int ans = 0;
        while (idx > 0)
        {
            ans += tree[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }

    vector<int> *nums_p;
    NumArray(vector<int> &nums)
    {
        nums_p = &nums;
        int n = nums.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            add(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        add(index, val - (*nums_p)[index]);
        (*nums_p)[index] = val;
    }

    int sumRange(int left, int right)
    {
        return prefix(right) - prefix(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
