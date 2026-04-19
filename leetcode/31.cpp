#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 轮椅
        //  next_permutation(nums.begin(), nums.end());

        // 正常思路：从后往前找一个升序对，找一个大于第一个元素的最小值与之交换，后面的升序排列

        int n = nums.size();
        int idx1 = -1;
        int idx2 = 0;
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                idx1 = i - 1;

                for (int j = i; j <= n; j++)
                {
                    if (j == n || nums[j] <= nums[idx1])
                    {
                        idx2 = j - 1;
                        break;
                    }
                }
                break;
            }
        }

        if (idx1 != -1)
        {

            swap(nums[idx1], nums[idx2]);
            for (int i = idx1 + 1; i <= (n - 1 + idx1 + 1) / 2; i++)
            {
                swap(nums[i], nums[n - 1 + idx1 + 1 - i]);
            }
        }
        else
        {
            for (int i = 0; i <= (n - 1) / 2; i++)
            {
                swap(nums[i], nums[n - 1 - i]);
            }
        }
    }
};
