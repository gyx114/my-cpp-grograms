#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
        {
            return root;
        }
        Node *beg = root;

        while (beg)
        {
            auto tmp = beg;
            while (tmp && tmp->left && tmp->right)
            {
                tmp->left->next = tmp->right;
                if (tmp->next)
                {
                    tmp->right->next = tmp->next->left;
                }
                tmp = tmp->next;
            }
            beg = beg->left;
        }
        return root;
    }
};
