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
    bool found_p = false;
    bool found_q = false;
    vector<TreeNode *> p_path;
    vector<TreeNode *> q_path;

    void backtrack(TreeNode *root, int &pval, int &qval)
    {
        if (!root || (found_p && found_q))
        {
            return;
        }

        if (root->val == pval)
        {
            found_p = true;
            p_path.push_back(root);
        }
        else if (root->val == qval)
        {
            found_q = true;
            q_path.push_back(root);
        }

        if (!found_p)
        {
            p_path.push_back(root);
        }
        if (!found_q)
        {
            q_path.push_back(root);
        }

        backtrack(root->left, pval, qval);
        backtrack(root->right, pval, qval);

        if (!found_p)
        {
            p_path.pop_back();
        }
        if (!found_q)
        {
            q_path.pop_back();
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int pval = p->val;
        int qval = q->val;
        backtrack(root, pval, qval);
        int n1 = p_path.size();
        int n2 = q_path.size();
        for (int i = 0; i < min(n1, n2); i++)
        {
            if (p_path[i] != q_path[i])
            {
                return p_path[i - 1];
            }
        }
        return n1 < n2 ? p : q;
    }
};
