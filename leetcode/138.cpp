#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    // 深拷贝，不过只是映射罢了
    unordered_map<Node *, Node *> mp;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        mp[nullptr] = nullptr;
        auto tmp_old = head;
        auto newhead = new Node(head->val);
        auto tmp_new = newhead;
        mp[tmp_old] = tmp_new;
        while (tmp_old != nullptr)
        {
            if (!mp.count(tmp_old->next))
            {
                mp.emplace(tmp_old->next, new Node(tmp_old->next->val));
            }
            tmp_new->next = mp[tmp_old->next];

            if (!mp.count(tmp_old->random))
            {
                mp.emplace(tmp_old->random, new Node(tmp_old->random->val));
            }
            tmp_new->random = mp[tmp_old->random];

            tmp_old = tmp_old->next;
            tmp_new = tmp_new->next;
        }
        return newhead;
    }
};
