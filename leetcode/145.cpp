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
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> ans;
        // 比前序遍历麻烦，需要判断栈中节点属于"根"还是"右"
        // pre用于记录上个被遍历的节点
        // 如果右节点是pre，说明当前节点属于"根"
        TreeNode *pre = nullptr;
        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            auto tmp = st.top();
            if (tmp->right && (pre == nullptr || tmp->right != pre))
            {
                root = tmp->right;
            }
            else
            {
                ans.push_back(tmp->val);
                pre = tmp;
                st.pop();
            }
        }
        return ans;
    }
};
