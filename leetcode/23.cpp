#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class greater_list
{
public:
    bool operator()(const ListNode *x, const ListNode *y) const
    {
        return x->val > y->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = new ListNode;
        ListNode *tmp = head;

        priority_queue<ListNode *, vector<ListNode *>, greater_list> prique;

        for (auto it = lists.begin(); it != lists.end();)
        {
            if (*it == nullptr)
            {
                it = lists.erase(it);
            }
            else
            {
                prique.push(*it);
                it++;
            }
        }

        while (prique.size())
        {
            tmp->next = prique.top();
            tmp = tmp->next;
            prique.pop();
            if (tmp->next)
            {
                prique.push(tmp->next);
            }
        }
        return head->next;
    }
};
