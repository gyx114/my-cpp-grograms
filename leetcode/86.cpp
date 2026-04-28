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

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *less_tail = dummy;
        ListNode *tmp = head;
        ListNode *pre = dummy;

        while (tmp != nullptr)
        {
            if (tmp->val >= x)
            {
                tmp = tmp->next;
                pre = pre->next;
            }
            else
            {
                if (tmp == less_tail->next)
                {
                    less_tail = tmp;
                    pre = tmp;
                    tmp = tmp->next;
                }
                else
                {
                    ListNode *lnext = less_tail->next;
                    less_tail->next = tmp;
                    pre->next = tmp->next;
                    tmp->next = lnext;
                    less_tail = less_tail->next;
                    pre = tmp;
                    tmp = tmp->next;
                }
            }
        }
        return dummy->next;
    }
};
