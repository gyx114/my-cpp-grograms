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
    stack<TreeNode *> st;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *tmp = root;
        TreeNode *pre = nullptr;
        while (!st.empty() || tmp)
        {
            if (tmp)
            {
                swap(tmp->left, tmp->right);
                if (tmp->left)
                {
                    st.push(tmp->left);
                    tmp->left = nullptr;
                }
                pre = tmp;
                tmp = tmp->right;
            }
            else if (!st.empty())
            {
                pre->right = st.top();
                st.pop();
                tmp = pre->right;
            }
        }
    }
};
