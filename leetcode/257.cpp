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
    vector<string> ans;
    string tmp;
    void backtrack(TreeNode *root)
    {

        if (!root)
        {
            return;
        }

        string addstr;

        if (!tmp.empty())
        {
            addstr = "->";
        }

        addstr += to_string(root->val);
        tmp += addstr;

        if (!root->left && !root->right)
        {
            ans.push_back(tmp);
        }
        else
        {
            backtrack(root->right);
            backtrack(root->left);
        }

        for (int i = 0; i < addstr.size(); i++)
        {
            tmp.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        backtrack(root);
        return ans;
    }
};
