#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *mktree(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = mktree(nums, l, mid - 1);
        root->right = mktree(nums, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return mktree(nums, 0, nums.size() - 1);
    }
};
