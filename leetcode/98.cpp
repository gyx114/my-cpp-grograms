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
    typedef long long ll;
    bool dfs(TreeNode *root, ll minval, ll maxval)
    // 为了防止左子树有比根大的或右子树有比根小的，需要用minval和maxval限定每个节点的范围
    {
        if (root == nullptr)
        {
            return true;
        }

        if (root->val >= maxval || root->val <= minval)
        {
            return false;
        }

        return dfs(root->left, minval, min(maxval, (ll)root->val)) && dfs(root->right, max(minval, (ll)root->val), maxval);
    }
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
