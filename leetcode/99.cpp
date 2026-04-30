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
    // bst特性：中序遍历单调递增

    void inorder(TreeNode *root, TreeNode *pre, vector<TreeNode *> &l_and_r)
    {
        if (root == nullptr)
        {
            return;
        }
        if (!root->left && !root->right)
        {
        }
    }

    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> l_and_r;
        TreeNode *pre = nullptr;
        TreeNode *tmp = root;
    }
};
