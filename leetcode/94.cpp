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
    // 左-根-右
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *t = root;
        while (t || !st.empty())
        {
            while (t)
            {
                st.push(t);
                t = t->left;
            }

            if (!st.empty())
            {
                t = st.top();
                st.pop();
                ans.push_back(t->val);
                t = t->right;
            }
        }
        return ans;
    }
};
