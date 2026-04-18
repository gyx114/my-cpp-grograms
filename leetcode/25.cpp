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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *tmp = head;
        ListNode *nextone = nullptr;
        int is_ok = 0;
        for (int i = 1; tmp != nullptr; i++)
        {
            if (i == k)
            {
                nextone = tmp->next;
                is_ok = 1;
                break;
            }
            tmp = tmp->next;
        }
        if (is_ok)
        {
            ListNode *pre = reverseKGroup(nextone, k);
            tmp = head;
            ListNode *tmpnxt = tmp->next;

            for (int i = 0; i < k; i++)
            {
                tmp->next = pre;
                pre = tmp;
                if (i == k - 1)
                {
                    return tmp;
                }
                else
                {
                    tmp = tmpnxt;
                    tmpnxt = tmp->next;
                }
            }
        }
        else
        {
            return head;
        }
        return nullptr;
    }
};
