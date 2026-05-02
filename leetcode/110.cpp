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
    inline bool diffsmall(int a, int b)
    {
        return a - b == 0 || a - b == 1 || a - b == -1;
    }
    int get_h_and_is_ok(TreeNode *root)
    // 返回-1表示这棵树不是平衡二叉树
    // 如果是平衡二叉树，返回其高度
    // 自底向上判断，避免重复计算高度
    {
        if (root == nullptr)
        {
            return 0;
        }
        int l = get_h_and_is_ok(root->left);
        int r = get_h_and_is_ok(root->right);
        if (l >= 0 && r >= 0 && diffsmall(l, r))
        {
            return max(l, r) + 1;
        }
        else
        {
            return -1;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return get_h_and_is_ok(root) != -1;
    }
};
