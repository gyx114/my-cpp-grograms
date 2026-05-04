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
            beg = nullptr;
            Node *pre = nullptr;
            while (tmp)
            {
                if (tmp->left && tmp->right)
                {
                    if (!beg)
                    {
                        beg = tmp->left;
                    }
                    if (pre)
                    {
                        pre->next = tmp->left;
                    }
                    tmp->left->next = tmp->right;
                    pre = tmp->right;
                }
                else
                {
                    if (tmp->left)
                    {
                        if (!beg)
                        {
                            beg = tmp->left;
                        }
                        if (pre)
                        {
                            pre->next = tmp->left;
                        }
                        pre = tmp->left;
                    }
                    else if (tmp->right)
                    {
                        if (!beg)
                        {
                            beg = tmp->right;
                        }
                        if (pre)
                        {
                            pre->next = tmp->right;
                        }
                        pre = tmp->right;
                    }
                }

                tmp = tmp->next;
            }
        }
        return root;
    }
};
