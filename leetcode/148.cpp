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
    ListNode *mergesort(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (!head->next)
        {
            return head;
        }
        auto slow = head;
        auto fast = head;
        while (fast && fast->next && fast->next->next)
        // 如果不加fast->next->next,对于两个节点的链表会死循环
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        slow = head;

        auto sorted_1 = mergesort(slow);
        auto sorted_2 = mergesort(fast);
        ListNode *ans_dummy = new ListNode();
        auto ans_tmp = ans_dummy;
        while (sorted_1 || sorted_2)
        {
            if (sorted_1 && sorted_2)
            {
                if (sorted_1->val < sorted_2->val)
                {
                    ans_tmp->next = sorted_1;
                    sorted_1 = sorted_1->next;
                    ans_tmp = ans_tmp->next;
                }
                else
                {
                    ans_tmp->next = sorted_2;
                    sorted_2 = sorted_2->next;
                    ans_tmp = ans_tmp->next;
                }
            }
            else if (sorted_1)
            {
                ans_tmp->next = sorted_1;
                sorted_1 = nullptr;
            }
            else
            {
                ans_tmp->next = sorted_2;
                sorted_2 = nullptr;
            }
        }
        auto ret = ans_dummy->next;
        delete ans_dummy;
        return ret;
    }
    ListNode *sortList(ListNode *head)
    {
        return mergesort(head);
    }
};
