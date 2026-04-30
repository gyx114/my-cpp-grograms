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
    bool is_same(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
        {
            return true;
        }
        else if (l && r && l->val == r->val)
        {
            return is_same(l->left, r->right) && is_same(l->right, r->left);
        }
        else
        {
            return false;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        return is_same(root, root);
    }
};
