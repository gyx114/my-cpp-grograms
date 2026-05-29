#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int val1 = p->val;
        int val2 = q->val;
        int val_rt = root->val;
        if (val1 > val_rt && val2 > val_rt)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (val1 < val_rt && val2 < val_rt)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
        return root;
    }
};
