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
    vector<vector<int>> ans;
    vector<TreeNode *> nodes;
    vector<int> nums;
    void backtrack(int targetSum)
    {
        auto cur = nodes.back();
        if (!cur->left && !cur->right)
        {
            if (targetSum == 0)
            {
                ans.push_back(nums);
            }
        }
        else
        {
            if (cur->left)
            {
                nodes.push_back(cur->left);
                nums.push_back(cur->left->val);
                backtrack(targetSum - cur->left->val);
                nums.pop_back();
                nodes.pop_back();
            }
            if (cur->right)
            {
                nodes.push_back(cur->right);
                nums.push_back(cur->right->val);
                backtrack(targetSum - cur->right->val);
                nums.pop_back();
                nodes.pop_back();
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return ans;
        }
        nodes.push_back(root);
        nums.push_back(root->val);
        backtrack(targetSum - root->val);
        return ans;
    }
};
