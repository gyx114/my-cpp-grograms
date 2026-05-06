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
    int maxsum = INT_MIN;
    int maxsinglePathSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        // 计算左右子节点的贡献
        int l = maxsinglePathSum(root->left);
        int r = maxsinglePathSum(root->right);
        maxsum = max(maxsum, root->val + max(0, l) + max(0, r));
        // 对每个节点，计算其路径和
        // 多用二元max，少用if-else分支

        return root->val + max(0, max(l, r));
    }

    int maxPathSum(TreeNode *root)
    {
        maxsinglePathSum(root);
        return maxsum;
    }
};
