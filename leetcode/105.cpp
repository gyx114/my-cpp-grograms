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
    TreeNode *genetree(vector<int> &preorder, vector<int> &inorder, int l1, int r1, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2)
        {
            return nullptr;
        }
        int rt = preorder[l1];
        TreeNode *root = new TreeNode(rt);
        if (l1 == r1)
        {
            return root;
        }
        int len_lft = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[l2 + i] == rt)
            {
                len_lft = i;
                break;
            }
        }

        TreeNode *lft = genetree(preorder, inorder, l1 + 1, l1 + len_lft, l2, l2 + len_lft - 1);
        TreeNode *rht = genetree(preorder, inorder, l1 + len_lft + 1, r1, l2 + len_lft + 1, r2);
        root->left = lft;
        root->right = rht;
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return genetree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
