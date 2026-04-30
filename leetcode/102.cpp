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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        vector<TreeNode *> nodes = {root};
        while (!nodes.empty())
        {
            vector<int> tmp;
            vector<TreeNode *> tmp_nd;
            for (auto p : nodes)
            {
                tmp.push_back(p->val);
                if (p->left)
                {
                    tmp_nd.push_back(p->left);
                }
                if (p->right)
                {
                    tmp_nd.push_back(p->right);
                }
            }
            ans.push_back(move(tmp));
            nodes.swap(tmp_nd);
        }
        return ans;
    }
};
