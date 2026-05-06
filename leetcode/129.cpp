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
    unsigned long long ans;
    unsigned long long tmp;
    void backtrack(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            ans += tmp;
            return;
        }
        if (root->left)
        {
            tmp = tmp * 10 + root->left->val;
            backtrack(root->left);
            tmp /= 10;
        }
        if (root->right)
        {
            tmp = tmp * 10 + root->right->val;
            backtrack(root->right);
            tmp /= 10;
        }
    }
    int sumNumbers(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(0, root, 0);
        backtrack(dummy);
        delete dummy;
        return ans;
    }
};
