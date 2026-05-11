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
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;
        while (!st.empty() || root)
        {
            while (root)
            {
                ans.push_back(root->val);
                if (root->right)
                {
                    st.push(root->right);
                }
                root = root->left;
            }
            if (!st.empty())
            {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};
