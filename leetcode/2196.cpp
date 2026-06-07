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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> val2nd;
        unordered_set<int> sons;
        for (auto x : descriptions)
        {
            int f = x[0];
            int s = x[1];
            bool is_lft = x[2];

            sons.insert(s);
            TreeNode *father = nullptr;
            TreeNode *son = nullptr;

            if (!val2nd.count(f))
            {
                val2nd[f] = new TreeNode(f);
            }
            father = val2nd[f];

            if (!val2nd.count(s))
            {
                val2nd[s] = new TreeNode(s);
            }
            son = val2nd[s];

            if (is_lft)
            {
                father->left = son;
            }
            else
            {
                father->right = son;
            }
        }
        TreeNode *root = nullptr;
        for (auto [val, nd] : val2nd)
        {
            if (!sons.count(val))
            {
                root = nd;
                break;
            }
        }
        return root;
    }
};
