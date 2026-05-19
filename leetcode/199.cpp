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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<int>();
        }
        vector<vector<TreeNode *>> layers(1, vector<TreeNode *>(1, root));
        while (true)
        {
            vector<TreeNode *> tmp;
            for (auto nd : layers.back())
            {
                if (nd->left)
                {
                    tmp.push_back(nd->left);
                }
                if (nd->right)
                {
                    tmp.push_back(nd->right);
                }
            }
            if (tmp.empty())
            {
                break;
            }
            else
            {
                layers.push_back(move(tmp));
            }
        }
        vector<int> ans;
        for (auto v : layers)
        {
            ans.push_back(v.back()->val);
        }
        return ans;
    }
};
