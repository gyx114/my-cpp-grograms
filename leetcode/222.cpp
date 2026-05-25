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
    // 对位置标号，看二进制，1向右，0向左
    bool check(TreeNode *root, int num, int h)
    {
        auto tmp = root;
        for (int i = h - 2; i >= 1; i--)
        {
            if ((num >> i) & 1)
            {
                tmp = tmp->right;
            }
            else
            {
                tmp = tmp->left;
            }
        }
        if (((num & 1) && tmp->right) || (!(num & 1) && tmp->left))
        {
            return true;
        }
        return false;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int h = 0;
        auto tmp = root;
        while (tmp)
        {
            h++;
            tmp = tmp->left;
        }

        // 二分找最终节点
        int l = 1;
        int r = (1 << h) - 1;
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (check(root, mid, h))
            {
                if (!check(root, mid + 1, h))
                {
                    return mid;
                }
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return mid;
    }
};
