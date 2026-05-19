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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode dummy(-1, head);
        auto pre = &dummy;
        auto tmp = head;
        while (tmp)
        {
            if (tmp->val == val)
            {
                pre->next = tmp->next;
                tmp = tmp->next;
            }
            else
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }
        return dummy.next;
    }
};
