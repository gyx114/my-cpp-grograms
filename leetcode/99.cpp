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

    void op(TreeNode *root)
    {
        if (bk && root->val <= bk->val)
        {
            if (!l)
            {
                l = bk;
            }
            r = root;
        }
        else
        {
            if (l && r && bk && bk == r && root->val > r->val && before_bk != l)
            {
                int tmp = l->val;
                l->val = r->val;
                r->val = tmp;
                is_ok = 1;
            }
            return;
        }
    }

    vector<TreeNode *> nodes;
    TreeNode *bk = nullptr;
    TreeNode *before_bk = nullptr;
    TreeNode *l = nullptr;
    TreeNode *r = nullptr;
    int is_ok = 0;
    void inorder(TreeNode *root)
    {
        if (is_ok)
        {
            return;
        }
        if (root == nullptr)
        {
            return;
        }
        else
        {
            inorder(root->left);
            op(root);
            before_bk = bk;
            bk = root;
            inorder(root->right);
        }
    }

    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (!is_ok)
        {
            int tmp = l->val;
            l->val = r->val;
            r->val = tmp;
        }
    }
};
