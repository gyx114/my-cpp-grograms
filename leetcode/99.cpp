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
        if (!nodes.empty() && root->val <= nodes.back()->val)
        {
            if (nodes.size() == 1 || nodes[nodes.size() - 2] <= nodes.back())
            {
                l = nodes.back();
            }
            r = root;
        }
        else
        {
            if (l && r && !nodes.empty() && nodes.back() == r && root->val > r->val)
            {
                int tmp = l->val;
                l->val = r->val;
                r->val = tmp;
                is_ok = 1;
                return;
            }
        }
    }

    vector<TreeNode *> nodes;
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
        else if (!root->left && !root->right)
        {
            op(root);
            nodes.push_back(root);
        }
        else
        {
            inorder(root->left);
            op(root);
            nodes.push_back(root);
            inorder(root->right);
        }
    }

    void recoverTree(TreeNode *root)
    {

        inorder(root);
    }
};
