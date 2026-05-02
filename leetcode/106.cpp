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
    TreeNode *mktree(vector<int> &inorder, vector<int> &postorder, int l1, int r1, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2)
        {
            return nullptr;
        }
        int rt = postorder[r2];

        TreeNode *root = new TreeNode(rt);
        if (l2 == r2)
        {
            return root;
        }
        int len_lft = 0;
        for (int i = 0;; i++)
        {
            if (inorder[l1 + i] == rt)
            {
                len_lft = i;
                break;
            }
        }

        root->left = mktree(inorder, postorder, l1, l1 + len_lft - 1, l2, l2 + len_lft - 1);
        root->right = mktree(inorder, postorder, l1 + len_lft + 1, r1, l2 + len_lft, r2 - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return mktree(inorder, postorder, 0, postorder.size() - 1, 0, postorder.size() - 1);
    }
};
