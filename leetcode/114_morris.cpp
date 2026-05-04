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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *tmp = root;
        TreeNode *pre = nullptr;
        while (tmp)
        {
            if (tmp->left)
            {
                pre = tmp->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = tmp->right;
                tmp->right = tmp->left;
                tmp->left = nullptr;
            }
            tmp = tmp->right;
        }
    }
};
